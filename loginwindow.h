#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include<C:/Users/Crocodiel/Documents/Tic_Tac/tictac.h>
#include <QLineEdit>
namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void startGame();
private:
    Ui::LoginWindow *ui;
    class TicTac *game;
    QLineEdit* input_name_first_gamer;
    QLineEdit* input_name_second_gamer;

};

#endif // LOGINWINDOW_H
