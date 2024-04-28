// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef GITBASEWIDGET_H
#define GITBASEWIDGET_H

#include <QWidget>

class GitBaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GitBaseWidget(QWidget *parent = nullptr)
        : QWidget(parent) {}

    virtual void setGitInfo(const QString &info) = 0;
};

#endif   // GITBASEWIDGET_H
