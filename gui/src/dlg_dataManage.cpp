//
// Created by yyw on 18-7-6.
//

#include "dlg_dataManage.h"
#include "../../processing/projectManager.h"
#include <QApplication>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QtCore/QProcess>
#include <QMessageBox>

dialog2::dialog2(QDialog *parent)
{
    log2.setupUi(this);

    connect(log2.input_bt, SIGNAL(clicked()), this, SLOT(select_input()));
    connect(log2.output_bt, SIGNAL(clicked()), this, SLOT(select_output()));
    connect(log2.process_bt, SIGNAL(clicked()), this, SLOT(process()));
    connect(log2.cancel_bt, SIGNAL(clicked()), this, SLOT(cancel()));
}

void dialog2::select_input()
{
    QString file_name = QFileDialog::getExistingDirectory(NULL,"Select Input Folder",".");
    log2.input_rt->setText(file_name);
}

void dialog2::select_output()
{
    QString file_name = QFileDialog::getExistingDirectory(NULL,"Select Output Folder",".");
    log2.output_rt->setText(file_name);
}

void dialog2::process()
{
    QString dataFolder = log2.input_rt->toPlainText();
    QString prjFolder = log2.output_rt->toPlainText();
    std::string dataF = std::string((const char *)dataFolder.toLocal8Bit());
    std::string prjF = std::string((const char *)prjFolder.toLocal8Bit());

    if(!boost::filesystem::exists(dataF) || !boost::filesystem::exists(prjF))
    {
        QMessageBox::information(NULL, "Warning","Please complete input and output path !", QMessageBox::Yes );
        return;
    }
    ppr::projectManager prjtest1(prjF,dataF);
    prjtest1.Load();

}

void dialog2::cancel()
{
//    QProcess process1(this);
//    process1.execute("gedit /home/congyz/workspace/Kylin_Cloud/test1.txt");
//    process1.waitForFinished();
//    process1.close();

    this->close();
}