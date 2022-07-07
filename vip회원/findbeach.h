#ifndef FINDBEACH_H
#define FINDBEACH_H

#include <QDialog>

namespace Ui {
class findbeach;
}

class findbeach : public QDialog
{
    Q_OBJECT

public:
    explicit findbeach(QWidget *parent = nullptr);
    ~findbeach();

private:
    Ui::findbeach *ui;
};

#endif // FINDBEACH_H
