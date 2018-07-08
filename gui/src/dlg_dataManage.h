//
// Created by yyw on 18-7-6.
//

#ifndef KYLIN_CLOUD_DIALOG2_H
#define KYLIN_CLOUD_DIALOG2_H

#endif //KYLIN_CLOUD_DIALOG2_H: DATA MANAGE DIALOG
#include "ui_dialog2.h"
#include <QDialog>

class dialog2:public QDialog
{
Q_OBJECT;
public:
    dialog2(QDialog* parent=0);

private slots:
    void select_input();
    void select_output();
    void process();
    void cancel();

private:
    Ui::Dialog log2;

};