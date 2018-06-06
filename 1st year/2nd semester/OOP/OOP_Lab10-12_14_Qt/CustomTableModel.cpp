#include "CustomTableModel.h"
#include <qbrush.h>
#include <qcolor.h>

CustomTableModel::~CustomTableModel()
{
}

int CustomTableModel::rowCount(const QModelIndex & parent) const
{
    return this->ctrl.getVector().size();
}

int CustomTableModel::columnCount(const QModelIndex & parent) const
{
    return 4;
}

QVariant CustomTableModel::data(const QModelIndex & index, int role) const
{
    //Student currentStudent = this->repo.getStudents()[index.row()];
    auto axolotl = this->ctrl.getVector()[index.row()];

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (index.column())
        {
        case 0:		// first column - name
            return QString::fromStdString(axolotl.getName());
        case 1:		// second column - group
            return QString::number(Axolotl::getIntFromBreed(axolotl.getBreed()));
        case 2:		// third column - lab grade
            return QString::fromStdString(to_string(axolotl.getAge()));
        case 3:		// fourth column - seminar grade
            return QString::fromStdString(axolotl.getPhoto());
        default:
            break;
        }
    }

    return QVariant();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString{ "Name" };
            case 1:
                return QString{ "Breed" };
            case 2:
                return QString{ "Age" };
            case 3:
                return QString{ "Photo" };
            default:
                break;
            }
        }
    }

    return QVariant();
}

bool CustomTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    int row = index.row();
    int col = index.column();

    //Student& currentStudent = this->repo.getStudents()[index.row()];
    Axolotl &ax = this->ctrl.getVector()[index.row()];

    if (role == Qt::EditRole)
    {
        switch (col)
        {
        case 0:
            break;
        case 1:
            break;
        case 2:
        {
            std::string age{ value.toString().toStdString() };
            //currentStudent.setLabGrade(std::stod(labGrade));
            ax.setAge(stoi(age));
            break;
        }
        case 3:
        {
            std::string photo{ value.toString().toStdString() };
            //currentStudent.setSeminarGrade(std::stod(seminarGrade));
            ax.setPhoto(photo);
        }
        }
    }

    emit dataChanged(index, index);
    return true;
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex & index) const
{
    int col = index.column();
    if (col == 0)
        return Qt::ItemFlags{};
    return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}
