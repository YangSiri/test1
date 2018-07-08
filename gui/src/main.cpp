//
// Created by jianping on 18-4-7.
//
#include <QtWidgets/QApplication>
#include "mainWindow.h"
#include "dlg_extract.h"
#include "dlg_dataManage.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    mainWindow w;
    w.setFixedSize(900, 300);
    w.show();
    return a.exec();
}
