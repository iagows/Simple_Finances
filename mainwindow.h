#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bt_open_clicked();

    void on_bt_file_clicked();

    void on_action_New_triggered();

    void on_action_Open_triggered();

private:
    Ui::MainWindow *ui;

    void showMessage(QString txt);
};

#endif // MAINWINDOW_H
