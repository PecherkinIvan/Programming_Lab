#include "mainwindow.h"
#include "ui_mainwindow.h"


bool mode=0; // Два режима, 0-Режим добавления создания обьекта, 1-Режим просмотра созданных и их редактирования.


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->pushButton_2->setVisible(false);

    colcyl = new CollectionCylinder;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete colcyl;
}

void MainWindow::Update_CroupBox()
{
    if(!mode)
    {
        ui->comboBox->blockSignals(true);
            ui->comboBox->clear();
            ui->comboBox->addItem("Треугольник");
            ui->comboBox->addItem("Круг");
            ui->comboBox->addItem("Звезда");
        ui->comboBox->blockSignals(false);
    }
    else
    {
        ui->comboBox->blockSignals(true);
            ui->comboBox->clear();
        ui->comboBox->blockSignals(false);

        int nc=1,nt=1,ns=1;
        Cylinder* cyl;

        for(int i=0; i< colcyl->getNumber(); i++)
        {
            cyl = colcyl->getCylinder(i);

            if(cyl->getType() == 0)
            {

                ui->comboBox->addItem("Цилиндр "+QString::number(nc));
                nc++;
            }
            if(cyl->getType() == 1)
            {

                ui->comboBox->addItem("Призма "+QString::number(nt));
                nt++;
             }
            if(cyl->getType() == 2)
            {

               ui->comboBox->addItem("Зведа "+QString::number(ns));
               ns++;
            }
        }
    }
}

void MainWindow::Interface_Display(string type)
{

    if(type == "Круг")
    {
        if(scene != nullptr)
        {
           delete scene;
           scene = nullptr;
        }

        ui->label->setText("Радиус");
        ui->label->setVisible(true);
        ui->lineEdit->setVisible(true);

        ui->label_2->setVisible(false);
        ui->lineEdit_2->setVisible(false);

        ui->label_3->setVisible(false);
        ui->lineEdit_3->setVisible(false);
    }

    if(type == "Треугольник")
    {

        if(scene != nullptr)
        {
            delete scene;
            scene = nullptr;
        }

        ui->label->setText("Сторона А");
        ui->label->setVisible(true);
        ui->lineEdit->setVisible(true);

        ui->label_2->setText("Сторона В");
        ui->label_2->setVisible(true);
        ui->lineEdit_2->setVisible(true);

        ui->label_3->setText("Сторона С");
        ui->label_3->setVisible(true);
        ui->lineEdit_3->setVisible(true);

    }

    if(type == "Звезда")
    {

        if(scene != nullptr)
        {
           delete scene;
           scene = nullptr;
        }

        ui->label->setText("Длинна осн. луча");
        ui->label->setVisible(true);
        ui->lineEdit->setVisible(true);

        ui->label_2->setVisible(false);
        ui->lineEdit_2->setVisible(false);

        ui->label_3->setVisible(false);
        ui->lineEdit_3->setVisible(false);
    }

}

void MainWindow::DrawCylinder(double r, double h)
{
    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    QPen blackpen(Qt::black); // Обычных линий
    blackpen.setWidth(2);
    blackpen.setColor("#1E90FF");

    QPen dotpen(Qt::black);  // Пунктирные линии
    dotpen.setStyle(Qt::DotLine);
    dotpen.setWidth(2);
    dotpen.setColor("#1E90FF");

    if(h>=r){             // Для нормального отображения большую из величин делаю 400px
       r = (400*r)/h;
       h = 400;
    }
    else{
       h = (200*h)/r;
       r = 200;
    }

    double d1 = r*2;           // Горизонтальный диаметр овала
    double d2 = 27*d1 / 100;  // Вертикальный диаметр овала

    scene->addEllipse(0, -h, d1, d2, blackpen);         // Верхний овал
    scene->addEllipse(0, 0, d1, d2, dotpen);           // Нижний пунктирный овал
    scene->addLine(0,-h+(d2/2), 0, d2/2, blackpen);    // Левое ребро
    scene->addLine(d1,-h+(d2/2), d1, d2/2, blackpen); // Правое ребро
    QPainterPath path;
    path.moveTo(0, d2/2);
    path.arcTo(0, 0, d1, d2, 180, 180);
    scene->addPath(path, blackpen);  // Передння не пунктирная дуга

}

void MainWindow::DrawPrism(double a, double b, double c, double h)
{
    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    QPen blackpen(Qt::black); // Обычных линий
    blackpen.setWidth(2);
    blackpen.setColor("#1E90FF");

    QPen dotpen(Qt::black);  // Пунктирные линии
    dotpen.setStyle(Qt::DotLine);
    dotpen.setWidth(2);
    dotpen.setColor("#1E90FF");

    if(h>=a && h>=b && h>=c)    // Для нормального отображения большую из величин делаю 400px
    {
        a = (a*400)/h;
        b = (b*400)/h;
        c = (c*400)/h;
        h = 400;
    }
    else if(b>=c && b>=a)
    {
        a = (a*400)/b;
        c = (c*400)/b;
        h = (h*400)/b;
        b = 400;
    }
    else if(c>=b && c>=a)
    {
        a = (a*400)/c;
        b = (b*400)/c;
        h = (h*400)/c;
        c = 400;
    }
    else
    {
        b = (b*400)/a;
        c = (c*400)/a;
        h = (h*400)/a;
        a = 400;
    }


    double x = ( b*b - (c*c - a*a) )/(2*a);  // Нахождение каординат вершины
    double y = sqrt( b*b - x*x);
    x = abs(x);  y = abs(y)*50 /100;        // y с учетом перспективы

    scene->addLine(0,0, a, 0, dotpen);   // A(0,0); B(0,a); C(x,y);
    scene->addLine(0, 0, x, y, blackpen);
    scene->addLine(x, y, a, 0, blackpen);

    scene->addLine(0,-h, a, -h, blackpen);
    scene->addLine(0, -h, x, -h+y, blackpen);
    scene->addLine(x, -h+y, a, -h, blackpen);

    scene->addLine(0,0,0,-h, blackpen);
    scene->addLine(a,0,a,-h, blackpen);
    scene->addLine(x,y,x,-h+y, blackpen);

}

void MainWindow::DrawStar(double d, double h)
{
    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    QPen blackpen(Qt::black); // Обычных линий
    blackpen.setWidth(2);
    blackpen.setColor("#1E90FF");

    QPen dotpen(Qt::black);  // Пунктирные линии
    dotpen.setStyle(Qt::DotLine);
    dotpen.setWidth(2);
    dotpen.setColor("#1E90FF");

    d = d*4.714;

    if(h >= d)
    {
        d = (d*400)/h;
        h = 400;
    }
    else
    {
        h = (h*330)/d;
        d = 330;
    }


    scene->addLine( d/2.276, -(d/3.67), d/1.83, -(d/2.76), dotpen);   // Нижняя звезда
    scene->addLine(d/1.83, -(d/2.76), d/1.535, -(d/3.67), dotpen);
    scene->addLine(d/1.535, -(d/3.67), d, -(d/3.67), dotpen);
    scene->addLine(d, -(d/3.67), d/1.138, -(d/4.342), blackpen);
        scene->addLine(d/1.138, -(d/4.342), d/1.352, -(d/5.5), dotpen);
    scene->addLine(d/1.352, -(d/5.5), d/1.138, -(d/22), dotpen);
    scene->addLine(d/1.138, -(d/22), d/1.83, -(d/7.3), blackpen);
    scene->addLine(d/1.83, -(d/7.3), d/4.648, -(d/22), blackpen);
    scene->addLine(d/4.648, -(d/22), d/2.84, -(d/5.5), dotpen);
    scene->addLine(d/2.84, -(d/5.5), d/4.648, -(d/4.342), dotpen);
        scene->addLine(d/4.648, -(d/4.342), d/11, -(d/3.67), blackpen);
    scene->addLine(d/11, -(d/3.67), d/2.276, -(d/3.67), dotpen);


    scene->addLine( d/2.276, -(d/3.67)-h, d/1.83, -(d/2.76)-h, blackpen);   // Верхняя звезда
    scene->addLine(d/1.83, -(d/2.76)-h, d/1.535, -(d/3.67)-h, blackpen);
    scene->addLine(d/1.535, -(d/3.67)-h, d, -(d/3.67)-h, blackpen);
    scene->addLine(d, -(d/3.67)-h, d/1.352, -(d/5.5)-h, blackpen);
    scene->addLine(d/1.352, -(d/5.5)-h, d/1.138, -(d/22)-h, blackpen);
    scene->addLine(d/1.138, -(d/22)-h, d/1.83, -(d/7.3)-h, blackpen);
    scene->addLine(d/1.83, -(d/7.3)-h, d/4.648, -(d/22)-h, blackpen);
    scene->addLine(d/4.648, -(d/22)-h, d/2.84, -(d/5.5)-h, blackpen);
    scene->addLine(d/2.84, -(d/5.5)-h, d/11, -(d/3.67)-h, blackpen);
    scene->addLine(d/11, -(d/3.67)-h, d/2.276, -(d/3.67)-h, blackpen);


    scene->addLine( d/2.276, -(d/3.67)-h, d/2.276, -(d/3.67), dotpen);   //Ребра
    scene->addLine(d/1.83, -(d/2.76)-h, d/1.83, -(d/2.76), dotpen);
    scene->addLine(d/1.535, -(d/3.67)-h, d/1.535, -(d/3.67), dotpen);
    scene->addLine(d, -(d/3.67)-h, d, -(d/3.67), blackpen);
    scene->addLine(d/1.352, -(d/5.5)-h, d/1.352, -(d/5.5), dotpen);
    scene->addLine(d/1.138, -(d/22)-h, d/1.138, -(d/22), blackpen);
    scene->addLine(d/1.83, -(d/7.3)-h, d/1.83, -(d/7.3), blackpen);
    scene->addLine(d/4.648, -(d/22)-h, d/4.648, -(d/22), blackpen);
    scene->addLine(d/2.84, -(d/5.5)-h, d/2.84, -(d/5.5), dotpen);
    scene->addLine(d/11, -(d/3.67)-h, d/11, -(d/3.67), blackpen);
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->statusbar->clearMessage();
    ui->statusbar->setStyleSheet(" ");

     Interface_Display(arg1.toStdString());

    if(mode)
    {
        int index = ui->comboBox->currentIndex();
        qDebug() << index;

        Cylinder* cyl = colcyl->getCylinder(index);

        if(cyl->getType() == 0)
        {
            Interface_Display("Круг");
            CircleCyl* cirCyl = static_cast<CircleCyl*>(cyl);

            ui->lineEdit->setText(QString::number( cirCyl->getRadius() ));
            ui->lineEdit_4->setText(QString::number( cirCyl->getHeight() ));
            ui->label_8->setText(QString::number( cirCyl->getSquare() ));
            ui->label_4->setText(QString::number( cirCyl->CalcValume() ));

            DrawCylinder(cirCyl->getRadius(), cirCyl->getHeight());

        }
        else if(cyl->getType() == 1)
        {
            Interface_Display("Треугольник");
            TriangleCyl* triCyl = static_cast<TriangleCyl*>(cyl);

            ui->lineEdit->setText(QString::number( triCyl->getA() ));
            ui->lineEdit->setText(QString::number( triCyl->getB() ));
            ui->lineEdit->setText(QString::number( triCyl->getC() ));
            ui->lineEdit_4->setText(QString::number( triCyl->getHeight() ));
            ui->label_8->setText(QString::number( triCyl->getSquare() ));
            ui->label_4->setText(QString::number( triCyl->CalcValume() ));

            DrawPrism(triCyl->getA(), triCyl->getB(), triCyl->getC(), triCyl->getHeight());

        }
        else if(cyl->getType() == 2)
        {
            Interface_Display("Звезда");
            StarCyl* staCyl = static_cast<StarCyl*>(cyl);

            ui->lineEdit->setText(QString::number( staCyl->getD() ));
            ui->lineEdit_4->setText(QString::number( staCyl->getHeight() ));
            ui->label_8->setText(QString::number( staCyl->getSquare() ));
            ui->label_4->setText(QString::number( staCyl->CalcValume() ));

            DrawStar(staCyl->getD(), staCyl->getHeight());
        }

    }

}


void MainWindow::on_pushButton_clicked()
{

   try
   {
    if(mode)
    {
        Cylinder* cyl = colcyl->getCylinder(ui->comboBox->currentIndex());

        if(cyl->getType() == 0)
        {
            double r, h, V, S;
            r = ui->lineEdit->text().toDouble();
            h = ui->lineEdit_4->text().toDouble();

            CircleCyl* circyl = static_cast<CircleCyl*>(colcyl->getCylinder(ui->comboBox->currentIndex()));
            cyl->setHeight(h);
            circyl->setRadius(r);
            S = circyl->getSquare();
            ui->label_8->setText(QString::number(S));
            V = cyl->CalcValume();
            ui->label_4->setText(QString::number(V));

            DrawCylinder(r, h);
        }
        else if(cyl->getType() == 1)
        {
            double a,b,c, h, V, S;
            a = ui->lineEdit->text().toDouble();
            b = ui->lineEdit_2->text().toDouble();
            c = ui->lineEdit_3->text().toDouble();
            h = ui->lineEdit_4->text().toDouble();

            TriangleCyl* tricyl = static_cast<TriangleCyl*>(colcyl->getCylinder(ui->comboBox->currentIndex()));
            cyl->setHeight(h);
            tricyl->setData(a,b,c);
            S = tricyl->getSquare();
            ui->label_8->setText(QString::number(S));
            V = cyl->CalcValume();
            ui->label_4->setText(QString::number(V));

            DrawPrism(a,b,c,h);
        }
        else if(cyl->getType() == 2)
        {
            double d, h, V, S;

            d = ui->lineEdit->text().toDouble();
            h = ui->lineEdit_4->text().toDouble();

            StarCyl* stacyl = static_cast<StarCyl*>(colcyl->getCylinder(ui->comboBox->currentIndex()));
            cyl->setHeight(h);
            stacyl->setD(d);
            S = stacyl->getSquare();
            ui->label_8->setText(QString::number(S));
            V = cyl->CalcValume();
            ui->label_4->setText(QString::number(V));

            DrawStar(d, h);
        }



    }
    else
    {
        if(ui->comboBox->currentIndex() == 1)
        {

            double r, h, V, S;
            r = ui->lineEdit->text().toDouble();
            h = ui->lineEdit_4->text().toDouble();


               ui->statusbar->clearMessage();
               ui->statusbar->setStyleSheet(" ");

               Figure* basis = new Circle(r);
               Cylinder* cyl = new CircleCyl(h, basis);

                S = basis->Calc_Square();
                ui->label_8->setText(QString::number(S));

                V = cyl->CalcValume();
                ui->label_4->setText(QString::number(V));
                delete basis;

                if(!mode)
                {
                  colcyl->addCylinder(cyl);

                  ui->statusbar->showMessage(" * фигура добавлена");
                  ui->statusbar->setStyleSheet("background:rgb(160, 255, 155);");

                }


                DrawCylinder(r, h);

        }

        if(ui->comboBox->currentIndex() == 0)
        {
            double a,b,c, h, V, S;
            a = ui->lineEdit->text().toDouble();
            b = ui->lineEdit_2->text().toDouble();
            c = ui->lineEdit_3->text().toDouble();
            h = ui->lineEdit_4->text().toDouble();


               ui->statusbar->clearMessage();
               ui->statusbar->setStyleSheet(" ");

               Figure* basis = new Triangle(a,b,c);
               Cylinder* cyl = new TriangleCyl(h, basis);

                S = basis->Calc_Square();
                ui->label_8->setText(QString::number(S));

                V = cyl->CalcValume();
                ui->label_4->setText(QString::number(V));
                delete basis;

                DrawPrism(a,b,c,h);

                if(!mode)
                {
                  colcyl->addCylinder(cyl);

                  ui->statusbar->showMessage(" * фигура добавлена");
                  ui->statusbar->setStyleSheet("background:rgb(160, 255, 155);");
                }


        }

        if(ui->comboBox->currentIndex() == 2)
        {
            double d, h, V, S;

            d = ui->lineEdit->text().toDouble();
            h = ui->lineEdit_4->text().toDouble();

               ui->statusbar->clearMessage();
               ui->statusbar->setStyleSheet(" ");

               Figure* basis = new Star(d);
               Cylinder* cyl = new StarCyl(h, basis);

               S = basis->Calc_Square();
               ui->label_8->setText(QString::number(S));

               V = cyl->CalcValume();
               ui->label_4->setText(QString::number(V));
               delete basis;

               DrawStar(d, h);


                if(!mode)
                {
                  colcyl->addCylinder(cyl);

                  ui->statusbar->showMessage(" * фигура добавлена");
                  ui->statusbar->setStyleSheet("background:rgb(160, 255, 155);");
                }


        }
    }
   }
    catch(MyEx& e)
    {
        ui->statusbar->showMessage(e.GetMessage());
        ui->statusbar->setStyleSheet("background:rgb(233,120,117);");
    }
    catch (...)
    {
        ui->statusbar->showMessage(" Catch : Неизвестная ошибка! ");
        ui->statusbar->setStyleSheet("background:rgb(233,120,117);");
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    if(scene != nullptr)
    {
       delete scene;
       scene = nullptr;
    }
    if(ui->comboBox->currentIndex() >= 0)
    {
        colcyl->delCylinder(ui->comboBox->currentIndex());
        Update_CroupBox();
        ui->statusbar->showMessage(" * фигура удалена");
    }
}

void MainWindow::on_action_2_triggered()
{
   mode = 0;

   ui->statusbar->clearMessage();
   ui->statusbar->setStyleSheet(" ");

   ui->label_8->clear();
   ui->label_4->clear();
   ui->lineEdit->clear();
   ui->lineEdit_2->clear();
   ui->lineEdit_3->clear();
   ui->lineEdit_4->clear();

   Update_CroupBox();
   on_comboBox_currentTextChanged("Треугольник");

   ui->pushButton->setText("Добавить");
   ui->pushButton_2->setVisible(false);

   if(scene != nullptr)
   {
      delete scene;
      scene = nullptr;
   }


}

void MainWindow::on_action1_triggered()
{
    mode = 1;

    ui->statusbar->clearMessage();
    ui->statusbar->setStyleSheet(" ");

    if(scene != nullptr)
    {
       delete scene;
       scene = nullptr;
    }

    Update_CroupBox();

    ui->pushButton->setText("Изменить");
    ui->pushButton_2->setVisible(true);

}


