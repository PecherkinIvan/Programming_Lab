#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QObject>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
//#include <QPainter>

#include "moveitem.h"
#include "Core.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void DrawCylinder(double, double);
    void DrawPrism(double, double, double, double);
    void DrawStar(double, double);


private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_pushButton_clicked();

    void on_action_2_triggered();

    void on_action1_triggered();

    void on_pushButton_2_clicked();

private:
    void Update_CroupBox();
    void Interface_Display(string);
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    CollectionCylinder* colcyl;

};
#endif // MAINWINDOW_H
