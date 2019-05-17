#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_open_clicked()
{
    if (ui->le_file->text().isEmpty()) {
        showMessage(tr("Choose database to open"));

    } else {
        QString path = ui->le_file->text();

        if (false) {

        } else {
            showMessage(tr("Error opening database"));
        }
    }
}

void MainWindow::showMessage(QString txt)
{
    this->ui->statusBar->showMessage(txt);
}

void MainWindow::on_bt_file_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open database"), "", tr("Database files (*.db)"));

    if (!path.isEmpty()) {
        this->ui->le_file->setText(path);
    }
}

void MainWindow::on_action_New_triggered()
{
    QString file("meow.db");
    //model.createDatabase(file);
    this->ui->le_file->setText("meow.db");
}

void MainWindow::on_action_Open_triggered()
{
    on_bt_file_clicked();
}
