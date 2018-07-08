//
// Created by congyz on 18-7-7.
//

#include "dlg_pointcloud.h"
#include <QFileDialog>
#include <QProgressBar>
#include "../../processing/projectManager.h"
#include <QMessageBox>

dlg_pointcloud::dlg_pointcloud(QDialog *parent) {
    dialog3.setupUi(this);

    connect(dialog3.pos_btn, SIGNAL(clicked()), this, SLOT(select_POS()));
    connect(dialog3.lasers_btn, SIGNAL(clicked()), this, SLOT(select_laser()));
    connect(dialog3.extract_btn, SIGNAL(clicked()), this, SLOT(process()));
    connect(dialog3.cancel_btn, SIGNAL(clicked()), this, SLOT(cancel()));
}

void dlg_pointcloud::select_POS()
{
    QString posPath = QFileDialog::getOpenFileName(this, tr("Select pos file folder"), "", tr("Feature Files (*.txt)"));
    dialog3.psoPath_te->setText(posPath + ".txt");
}

void dlg_pointcloud::select_laser()
{
//    QString featurePath = QFileDialog::getExistingDirectory(NULL, "Select output feature file folder ", ".");
    QString laserPath = QFileDialog::getExistingDirectory(NULL, "Select input laser folder ", ".");
    dialog3.laser_te->setText(laserPath);
}

void dlg_pointcloud::process()
{
    dialog3.progressBar->setMinimum(0);
    dialog3.progressBar->setMaximum(0);

    QString posfile = dialog3.psoPath_te->toPlainText();
    QString laserFolder = dialog3.laser_te->toPlainText();
    std::string posFile = std::string((const char *)posfile.toLocal8Bit());
    std::string laserF = std::string((const char *)laserFolder.toLocal8Bit());

    if(!boost::filesystem::exists(posFile) || !boost::filesystem::exists(laserF))
    {
        QMessageBox::information(NULL, "Warning","Please complete pos and laser path !", QMessageBox::Yes );
        return;
    }

    ppr::compute_pointCloud(posFile,laserF);

    dialog3.progressBar->close();

}

void dlg_pointcloud::cancel()
{
   this->close();
}