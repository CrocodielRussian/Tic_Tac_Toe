#ifndef TICTAC_H
#define TICTAC_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

// #include<C:/Users/Crocodiel/Documents/Tic_Tac/loginwindow.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class TicTac;
}
QT_END_NAMESPACE

class TicTac : public QMainWindow
{
    Q_OBJECT

public:
    TicTac(QString first_name, QString second_name, QWidget *parent = nullptr);
    ~TicTac();

private slots:
    void setCross(QPushButton* btn, int i, int j);

private:
    Ui::TicTac *ui;

    int current_step;
    bool end_game;
    int arr[3][3] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    QString first_name, second_name;
    QLabel *title;
    QGridLayout* playground;
    QPushButton* restart;

    void checkWin();
    void setEndGame(int flag);
    void restartGame();
};
#endif // TICTAC_H
