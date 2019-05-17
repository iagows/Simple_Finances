#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mountTables();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mountTables()
{
    QStringList list;
    list << tr("Description") << tr("Date/Time") << tr("Amount");
    ui->tw_income->setHorizontalHeaderLabels(list);
}
