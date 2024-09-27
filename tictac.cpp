#include "tictac.h"
#include "./ui_tictac.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QSize>
#include <QFont>
#include <iostream>
#include <QMessageBox>
#include<string>
TicTac::TicTac(QString first_name, QString second_name, QWidget *parent)
    : QMainWindow(parent),
    current_step(0),
    first_name(first_name),
    second_name(second_name),
    end_game(false),
    ui(new Ui::TicTac)
{
    ui->setupUi(this);
    this->setWindowTitle("Игра Крестики-Нолики");
    QVBoxLayout* window_layout = new QVBoxLayout();
    title = new QLabel("Игра 3X3");
    title->setStyleSheet("QLabel { font-weight: bold; font-size: 20px;}");
    title->setAlignment(Qt::AlignHCenter);
    window_layout->addWidget(title);

    playground = new QGridLayout();
    QWidget* widget_playground = new QWidget();
    playground->setSizeConstraint(QLayout::SetFixedSize);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            QPushButton* button = new QPushButton();

            QSize* button_size = new QSize();
            button_size->setWidth(100);
            button_size->setHeight(100);
            button->setFixedSize(*button_size);

            connect(button, &QPushButton::clicked, this, [this, button, i, j](){ setCross(button, i, j); });
            playground->addWidget(button, i, j);
        }
    }
    restart = new QPushButton("Начать заново");
    restart->setVisible(0);
    connect(restart, &QPushButton::clicked, this, [this](){ restartGame();});
    window_layout->addWidget(restart);

    window_layout->setAlignment(Qt::AlignHCenter);
    widget_playground->setLayout(playground);
    window_layout->addWidget(widget_playground);

    QWidget* window = new QWidget();
    window->setLayout(window_layout);
    setCentralWidget(window);
}
void TicTac::restartGame(){
    current_step = 0;
    this->restart->setVisible(0);
    end_game = 0;
    int cnt = 2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            QLayoutItem* elem = playground->itemAtPosition(i, j);
            QWidget* widget = elem->widget();
            QPushButton* button = dynamic_cast<QPushButton*>(widget);
            button->setText("");
            this->arr[i][j] = cnt;
            cnt++;
        }
    }
    title->setText("Игра 3X3");
}
void TicTac::setCross(QPushButton* btn, int i, int j){
    if(end_game)
        return;
    if(this->arr[i][j] >= 2){
        if(this->current_step == 0){
            btn->setText("X");
            btn->setStyleSheet("QPushButton { font-weight: bold; font-size: 60px; color: red;}");
            this->arr[i][j] = 0;
            checkWin();
            this->current_step = 1;
        }else{
            btn->setText("O");
            btn->setStyleSheet("QPushButton { font-weight: bold; font-size: 60px; color: blue;}");
            this->arr[i][j] = 1;
            checkWin();
            this->current_step = 0;
        }
    }

}
void TicTac::setEndGame(int flag){
    if(flag == 1){
        std::string winner_str;

        if(this->current_step == 0){
            if(!this->first_name.isEmpty()){
                winner_str = "Победил " + this->first_name.toStdString();
            }else{
                QString winner = QString::number(this->current_step + 1);
                winner_str = "Победил Игрок " + winner.toStdString();
            }
        }else{
            if(!this->second_name.isEmpty()){
                winner_str = "Победил " + this->second_name.toStdString();
            }else{
                QString winner = QString::number(this->current_step + 1);
                winner_str = "Победил Игрок " + winner.toStdString();
            }
        }
        const char *f = winner_str.data();
        QString final(f);
        title->setText(final);
        this->end_game = true;
        emit(this->restart->setVisible(1));
    }else if(flag == 2){
        title->setText("Ничья");
        this->end_game = true;
        emit(this->restart->setVisible(1));
    }
}
void TicTac::checkWin(){
    // 0 - continue game
    // 1 - end game; winner exist
    // 2 - end game; winner doen't exist
    if((this->arr[0][0] == this->arr[1][1] && this->arr[1][1] == this->arr[2][2]) || (this->arr[1][1] == this->arr[0][2] && this->arr[2][0] == this->arr[1][1])){
        setEndGame(1);
        return;
    }
    for(int j = 0; j < 3; j++){
        if(this->arr[j][0] == this->arr[j][1] && this->arr[j][1] == this->arr[j][2]){
            setEndGame(1);
            return;
        }
        if(this->arr[0][j] == this->arr[1][j] && this->arr[1][j] == this->arr[2][j]){
            setEndGame(1);
            return;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(this->arr[i][j] > 1){
                return;
            }
        }
    }
    setEndGame(2);
}

TicTac::~TicTac()
{
    delete ui;
}
