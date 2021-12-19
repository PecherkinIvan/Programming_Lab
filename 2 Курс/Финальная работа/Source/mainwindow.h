#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPainter>

#include "LibCylinder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void DrawCylinder(double, double);     // Нахождение каординат и отрисовка
    void DrawPrism(double, double, double, double);
    void DrawStar(double, double);


private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);  // Обработка событий после выбора...

    void on_pushButton_clicked();  // Кнопка ДОБАВИТЬ & ИЗМЕНИТЬ обработка событий после нажатия

    void on_action_2_triggered();  // Кнопка УДАЛИТЬ скрыта в режиме mode=0, запускает удаление обьетка активного в comboBox

    void on_action1_triggered();  // Кнопка меню, изменяет режим на изменение созданных фигур, работа с колекцией.

    void on_pushButton_2_clicked(); // Кнопка меню, изменяет режим на создание новых фигур.

private:
    void Update_CroupBox();          // Обновление панели выбора, динамически изменяется в зависимости от режима
    void Interface_Display(string); // Динамическое изменение правой панели в зависимости от выбора
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    CollectionCylinder* colcyl;  // Обьект хранит вектор с указателеми на Cylinder.

};
#endif // MAINWINDOW_H
