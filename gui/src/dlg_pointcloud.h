//
// Created by congyz on 18-7-7.
//

#ifndef KYLIN_CLOUD_DLG_POINTCLOUD_H
#define KYLIN_CLOUD_DLG_POINTCLOUD_H

#include "ui_dlg_pointcloud.h"
#include <QtWidgets/QDialog>

class dlg_pointcloud:public QDialog
{
    Q_OBJECT;
public:
    dlg_pointcloud(QDialog* parent = 0);

private slots:
    void select_POS();
    void select_laser();
    void process();
    void cancel();

private:
    Ui::dlg3 dialog3;

};
#endif //KYLIN_CLOUD_DLG_POINTCLOUD_H
