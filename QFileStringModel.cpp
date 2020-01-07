#include "QFileStringModel.h"

QFileStringModel::QFileStringModel(QObject *parent)
    :QAbstractTableModel(parent)
{
}

void QFileStringModel::setFileString(QVector<QPair<QString, QString> > &vector)
{
    vectorFilePaths = vector;
    reset();
}

int QFileStringModel::rowCount(const QModelIndex &parent) const
{
    return vectorFilePaths.count();
}

int QFileStringModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant QFileStringModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    switch(role)
    {
    case Qt::TextAlignmentRole:
        return int(Qt::AlignLeft);
        break;
    case Qt::DisplayRole:
        {
            if(index.column()==0)
                return vectorFilePaths[index.row()].first;

            if(index.column()==1)
                return vectorFilePaths[index.row()].second;

            return QVariant();
        }
        break;

    case Qt::FontRole:
        return QFont::System;
        break;
    }
    return QVariant();
}

QVariant QFileStringModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            if(section==0)
                return "File Name";
            if(section==1)
                return "File Path";
        }

        if(orientation == Qt::Vertical)
        {
            return section;
        }
    }

    return QVariant();
}

bool QFileStringModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

Qt::ItemFlags QFileStringModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index)|Qt::ItemIsSelectable;
}

void QFileStringModel::AppendFileString(QString Name, QString Path)
{
    QPair<QString,QString> pair(Name,Path);
    vectorFilePaths.append(pair);
    reset();
}

void QFileStringModel::RemoveAll()
{
    vectorFilePaths.remove(0,vectorFilePaths.count());
    reset();
}

QTreeWidgetItem* QFileStringModel::GetXmlNodeTreeItems(int index)
{
    if((index<0)&&(index>vectorXmlNodeItems.count()))
        return NULL;
    return vectorXmlNodeItems.at(index);
}

void QFileStringModel::OpenFile()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(NULL, tr("Open Files"),"/",tr("XML (*.xml)"));

    if(fileNames.isEmpty())
        return ;

    QPair<QString,QString> pair;
    QString fileName;
    foreach (fileName, fileNames)
    {
        GetFileNameAndPath(fileName,pair.first,pair.second);
        AppendFileString(pair.first,pair.second);
        vectorXmlNodeItems.append(XMLFileTrav(fileName));
    }
}



bool QFileStringModel::GetFileNameAndPath(const QString &FileString,QString &Name,QString &Path)
{
    if(FileString.isEmpty())
        return false;
    Name = "";
    Path = "";

    int i,j;

    if(QSysInfo::windowsVersion()<QSysInfo::WV_VISTA)
        i = FileString.lastIndexOf("/");
    else
        i = FileString.lastIndexOf("\\");
    if(i == -1)
        return false;
    j = FileString.length() - i;

    Path = FileString.left(i + 1);
    Name = FileString.right(j - 1);

    return true;
}

QTreeWidgetItem* QFileStringModel::XMLFileTrav(QString &FileName)
{
    QFile xmlfile(FileName);
    if(!xmlfile.open(QFile::ReadOnly | QFile::Text))
        return NULL;
    QTreeWidgetItem *TreeRootNode = new QTreeWidgetItem;

    TreeRootNode->setText(0,FileName);
    QDomDocument domDocument;
    domDocument.setContent(&xmlfile);
    QDomElement root = domDocument.documentElement();

    DomNodeTrav(root,TreeRootNode);

    return TreeRootNode;
}

void QFileStringModel::DomNodeTrav(QDomNode &DomElement, QTreeWidgetItem *ParentItem)
{
    QDomNodeList Nodes;
    QDomNode Node;
    int i,n;
    Nodes = DomElement.childNodes();
    i = 0;
    n = Nodes.length();
    for(i=0;i<n;i++)
    {
        Node = Nodes.at(i);
        if(Node.nodeName()!="#text")
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ParentItem);
            ParentItem->addChild(item);
            item->setText(0,Node.nodeName());
            if(Node.hasChildNodes())
                DomNodeTrav(Node,item);
        }
    }

}
