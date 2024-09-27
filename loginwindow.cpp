#include "loginwindow.h"
#include "tictac.h"
#include "ui_loginwindow.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <iostream>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Игра Крестики-Нолики");

    QVBoxLayout* window_layout = new QVBoxLayout();
    window_layout->setSpacing(0);
    window_layout->setAlignment(Qt::AlignHCenter);

    QSize* input_size = new QSize();
    input_size->setWidth(400);
    input_size->setHeight(25);

    QLabel* first_gamer = new QLabel("Имя первого игрока");
    first_gamer->setMargin(0);
    first_gamer->setStyleSheet("QLabel { font-weight: bold; font-size: 18px; font-family: Verdana;}");

    input_name_first_gamer = new QLineEdit();
    input_name_first_gamer->setMaxLength(10);
    QFont littleFont("Courier New", 10);
    input_name_first_gamer->setFont(littleFont);
    input_name_first_gamer->setFixedSize(*input_size);

    QLabel* second_gamer = new QLabel("Имя второго игрока");
    second_gamer->setMargin(0);
    second_gamer->setStyleSheet("QLabel { font-weight: bold; font-size: 18px; font-family: Verdana;}");

    input_name_second_gamer = new QLineEdit();
    input_name_second_gamer->setMaxLength(10);
    input_name_second_gamer->setFixedSize(*input_size);

    window_layout->addWidget(first_gamer);
    window_layout->addWidget(input_name_first_gamer);
    window_layout->addWidget(second_gamer);
    window_layout->addWidget(input_name_second_gamer);

    QPushButton* confirm = new QPushButton("Начать");

    QSize* confirm_size = new QSize();
    confirm_size->setWidth(400);
    confirm_size->setHeight(50);
    confirm->setFixedSize(*confirm_size);

    connect(confirm, &QPushButton::clicked, this, &startGame);

    window_layout->addWidget(confirm);

    QWidget* window = new QWidget();
    window->setLayout(window_layout);
    setCentralWidget(window);
}

void LoginWindow::startGame()
{
    game = new TicTac(input_name_first_gamer->text(), input_name_second_gamer->text());
    game->show();
    this->close();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
