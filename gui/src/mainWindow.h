//
// Created by jianping on 18-4-7.
//

#ifndef QOSGFRAMEWORK_MAINWINDOW_H
#define QOSGFRAMEWORK_MAINWINDOW_H
#include <QtWidgets/QWidget>
#include "ui_mainWindow.h"
#include "ldOsgWidget.h"
#include <osg/Shape>
#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osg/Switch>
#include "ui_dlg_hey.h"
#include "ui_dialog2.h"

class mainWindow :public QMainWindow
{
Q_OBJECT
public:
    mainWindow(QWidget* parent = 0){
        ui.setupUi(this);

        connect(ui.input_btn,SIGNAL(clicked()),this,SLOT(show_log2()));
        connect(ui.compute_laser,SIGNAL(clicked()),this,SLOT(show_dlg_pointcloud()));
        connect(ui.extract_btn,SIGNAL(clicked()),this,SLOT(show_hey()));
//        connect(ui.match,SIGNAL(clicked()),this,SLOT(show_log2()));
//        connect(ui.reconstruct,SIGNAL(clicked()),this,SLOT(show_log2()));
    }
    //~mainWindow();

private slots:
    void show_hey();
    void show_log2();
    void show_dlg_pointcloud();


private:
    Ui::MainWindow ui;
};


#endif //QOSGFRAMEWORK_MAINWINDOW_H
