//
//CONG
//

#include "dlg_extract.h"
#include "dlg_dataManage.h"
#include "../../processing/projectManager.h"
#include <QApplication>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QtCore/QProcess>
#include <QMessageBox>

dlg_hey::dlg_hey(QDialog *parent)
{
    dlg_extract.setupUi(this);
    connect(dlg_extract.imgs_btn, SIGNAL(clicked()), this, SLOT(select_input()));
    connect(dlg_extract.features_btn, SIGNAL(clicked()), this, SLOT(select_output()));
    connect(dlg_extract.extract_btn, SIGNAL(clicked()), this, SLOT(process()));
    connect(dlg_extract.cancel_btn, SIGNAL(clicked()), this, SLOT(cancel()));

}

void dlg_hey::select_output()
{
    QString featurePath = QFileDialog::getSaveFileName(this, tr("Select output feature file folder"), "", tr("Feature Files (*.ql)"));
    dlg_extract.imgsPath_te->setText(featurePath + ".ql");
}

void dlg_hey::select_input()
{
//    QString featurePath = QFileDialog::getExistingDirectory(NULL, "Select output feature file folder ", ".");
    QString imgPath = QFileDialog::getExistingDirectory(NULL, "Select input images folder ", ".");
    dlg_extract.imgsPath_te->setText(imgPath);
}

void dlg_hey::process()
{

}

void dlg_hey::cancel()
{
    this->close();
}