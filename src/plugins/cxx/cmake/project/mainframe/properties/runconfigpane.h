// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef RUNCONFIGPANE_H
#define RUNCONFIGPANE_H

#include "configutil.h"

#include <QWidget>

class RunConfigPanePrivate;
class RunConfigPane : public QWidget
{
    Q_OBJECT
public:
    explicit RunConfigPane(QWidget *parent = nullptr);
    ~RunConfigPane();

    void bindValues(config::RunParam *runParam);

signals:

public slots:

private:
    void setupUi();

    RunConfigPanePrivate *const d;
};

#endif // RUNCONFIGPANE_H
