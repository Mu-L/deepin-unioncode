// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef ENVIRONMENTWIDGET_H
#define ENVIRONMENTWIDGET_H

#include "configutil.h"
#include <DFrame>

#include <QAbstractTableModel>

enum EnvType {
    BuildCfg,
    RunCfg
};

class EnvironmentModelPrivate;
class EnvironmentModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum ColumnType
    {
        kVaribale,
        kValue,
        kColumnCount
    };

    explicit EnvironmentModel(QObject *parent = nullptr);
    ~EnvironmentModel() override;

    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QModelIndex append(const QString &key, const QString &value);
    void remove(QModelIndex &index);
    void update(const QMap<QString, QString> &data);
    const QMap<QString, QString> getEnvironment() const;

private:
    EnvironmentModelPrivate *const d;
};

class EnvironmentWidgetPrivate;
class EnvironmentWidget : public DTK_WIDGET_NAMESPACE::DFrame
{
    Q_OBJECT

public:
    explicit EnvironmentWidget(QWidget *parent = nullptr, EnvType type = EnvType::BuildCfg);
    virtual ~EnvironmentWidget();

    void appendRow();
    void deleteRow();
    void initModel();

    void getValues(config::EnvironmentItem &env);
    void setValues(const config::EnvironmentItem &env);
    void updateEnvList(config::EnvironmentItem *env);

signals:
    void envUpdated();

private:
    EnvironmentWidgetPrivate *const d;
};

#endif // ENVIRONMENTWIDGET_H
