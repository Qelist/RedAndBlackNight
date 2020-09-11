#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(1200,800);

    ui->stackedWidget->setCurrentIndex(0);
    ui->label->setPixmap(QPixmap(":/Image/RBNlogo.jpg"));
    connect(ui->btn_startgame,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);

    });

    connect(ui->btn_endgame,&QPushButton::clicked,this,&Widget::close);

    connect(ui->btn_back,&QPushButton::clicked,[=]{
        ui->stackedWidget->setCurrentIndex(0);

    });
}

Widget::~Widget()
{
    delete ui;
}
