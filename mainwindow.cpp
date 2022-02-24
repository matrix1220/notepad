#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    opened = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_us_triggered()
{
    QMessageBox::information(this,"About us","Mukhiddin - U1910274\nAzizbek - U1910288\nShokhrukhmirzo - U1910272");
}

void MainWindow::on_actionOpen_triggered()
{
    file_path = QFileDialog::getOpenFileName(this,tr("Open Text File"), "",tr("Text File (*.txt);;All Files (*)"));
    QFile file(file_path);
    if (!file.open(QFile::ReadOnly | QFile::Text)) QMessageBox::information(this, "Error :", file.errorString());;
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    opened = true;
    this->setWindowTitle("ourNotepad " + file_path);
}

void MainWindow::on_actionSave_triggered()
{
    if(!opened) {
        file_path = QFileDialog::getSaveFileName(this,tr("Save Text File"), "",tr("Text File (*.txt);;All Files (*)"));
    }
    QFile file(file_path);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
    opened = true;
    this->setWindowTitle("ourNotepad " + file_path);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionClose_file_triggered()
{
    opened =false;
    ui->textEdit->setText("");
    this->setWindowTitle("ourNotepad");
}

void MainWindow::on_actionAbout_program_triggered()
{
    QMessageBox::information(this,"About program","This is just for editing text files!");
}
