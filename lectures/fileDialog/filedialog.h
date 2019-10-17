#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include "ui_filedialog.h"

class QModelIndex;
class QDirModel;
class QItemSelectionModel;

namespace Ui {
class FileDialog;
}

class FileDialog : public QDialog, private Ui::FileDialog
{
    Q_OBJECT

public:
    FileDialog(QWidget *parent = nullptr);
    QStringList selectedFiles();
    ~FileDialog();

protected slots:
    void switchToDir(const QModelIndex& index);
    void syncActive(const QModelIndex& index);
    void switchView();

private:
    Ui::FileDialog *ui;

    QItemSelectionModel *selModel;
    QDirModel *dirModel;
};

#endif // FILEDIALOG_H
