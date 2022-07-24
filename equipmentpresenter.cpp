#include "equipmentpresenter.h"

EquipmentPresenter::EquipmentPresenter(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant EquipmentPresenter::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex EquipmentPresenter::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex EquipmentPresenter::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int EquipmentPresenter::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int EquipmentPresenter::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant EquipmentPresenter::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
