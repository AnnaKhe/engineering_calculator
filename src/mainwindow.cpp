#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>


double num_first;
const int max_digits = 12;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_opposite, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_pow, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_log, SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_opposite->setCheckable(true);
    ui->pushButton_pow->setCheckable(true);
    ui->pushButton_sqrt->setCheckable(true);
    ui->pushButton_log->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{    double all_numbers;
     QString new_label;
     QPushButton *button = qobject_cast<QPushButton*>(sender());
     QString currentText = ui->result_show->text();
     if (currentText.contains('.') || button->text() == ".") {
         new_label = currentText + button->text();
        } else {
            all_numbers = (currentText + button->text()).toDouble();
            new_label = QString::number(all_numbers, 'g', max_digits);
        }

      ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))
    {
    ui->result_show->setText(ui->result_show->text() + ".");
    }
}

void MainWindow::operations()
{

    QPushButton *button = qobject_cast<QPushButton*>(sender()); //отслеживание на какую кнопку нажато
    double all_numbers;
    QString new_label;

    if(button->text() == "+/-"){
    all_numbers = (ui->result_show->text()).toDouble();
    all_numbers =  all_numbers * -1;
    new_label = QString::number(all_numbers, 'g', max_digits);
    ui->result_show->setText(new_label);
    }
    else if(button->text() == "%"){
    all_numbers = (ui->result_show->text()).toDouble();
    all_numbers =  all_numbers * 0.01;
    new_label = QString::number(all_numbers, 'g', max_digits);
    ui->result_show->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);

}


void MainWindow::on_pushButton_clear_clicked()
{

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_opposite->setChecked(false);
    ui->pushButton_pow->setChecked(false);
    ui->pushButton_sqrt->setChecked(false);
    ui->pushButton_log->setChecked(false);
    ui->result_show->setText("0");
}


void MainWindow::on_pushButton_equals_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', max_digits);
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()){
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', max_digits);
        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked()){
        if(num_second == 0) {
        ui->result_show->setText("ERROR");
        ui->pushButton_plus->setChecked(false);
        }else{
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', max_digits);
            ui->result_show->setText(new_label);
            ui->pushButton_divide->setChecked(false);
        }
    }
    else if(ui->pushButton_mult->isChecked()){
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', max_digits);
        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);
    }
    else if(ui->pushButton_pow->isChecked()){
        labelNumber = pow(num_first, num_second);
        new_label = QString::number(labelNumber, 'g', max_digits);
        ui->result_show->setText(new_label);
        ui->pushButton_pow->setChecked(false);
    }
    else if(ui->pushButton_log->isChecked()){
        if(num_first <= 0) {
        ui->result_show->setText("ERROR");
        ui->pushButton_plus->setChecked(false);
        }else{
        labelNumber = log(num_first);
        new_label = QString::number(labelNumber, 'g', max_digits);
        ui->result_show->setText(new_label);
        ui->pushButton_log->setChecked(false);
        }
    }
    else if(ui->pushButton_opposite->isChecked()){
        if(num_first == 0) {
        ui->result_show->setText("ERROR");
        ui->pushButton_plus->setChecked(false);
        }
        else{
            labelNumber = 1 / num_first;
            new_label = QString::number(labelNumber, 'g', max_digits);
            ui->result_show->setText(new_label);
            ui->pushButton_opposite->setChecked(false);
            }
    }
    else if(ui->pushButton_sqrt->isChecked()){
        if(num_first < 0) {
        ui->result_show->setText("ERROR");
        ui->pushButton_plus->setChecked(false);
        }
        else{
            labelNumber = sqrt(num_first);
            new_label = QString::number(labelNumber, 'g', max_digits);
            ui->result_show->setText(new_label);
            ui->pushButton_sqrt->setChecked(false);
            }
    }
}

