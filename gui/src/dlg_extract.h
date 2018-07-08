//
//   CONG
//

#include "ui_dlg_hey.h"
#include <QDialog>

class dlg_hey:public QDialog
{
    Q_OBJECT;
public:
    dlg_hey(QDialog* parent=0);

private slots:

    void select_input();
    void select_output();
    void process();
    void cancel();

private:
    Ui::dlg2 dlg_extract;

};