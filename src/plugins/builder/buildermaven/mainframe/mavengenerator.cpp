﻿/*
 * Copyright (C) 2022 Uniontech Software Technology Co., Ltd.
 *
 * Author:     zhouyi<zhouyi1@uniontech.com>
 *
 * Maintainer: zhouyi<zhouyi1@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "mavengenerator.h"
#include "parser/mavenparser.h"
#include "services/window/windowservice.h"
#include "services/builder/builderservice.h"

class MavenGeneratorPrivate
{
    friend class MavenGenerator;
};

MavenGenerator::MavenGenerator()
    : d(new MavenGeneratorPrivate())
{

}

MavenGenerator::~MavenGenerator()
{
    if (d)
        delete d;
}

void MavenGenerator::getMenuCommand(BuildCommandInfo &info, const BuildMenuType buildMenuType)
{
    info.program = "mvn";
    switch (buildMenuType) {
    case Build:
        info.arguments.append("compile");
        break;
    case Clean:
        info.arguments.append("clean");
        break;
    }
}

void MavenGenerator::appendOutputParser(std::unique_ptr<IOutputParser> &outputParser)
{
    if (outputParser) {
        outputParser->takeOutputParserChain();
        outputParser->appendOutputParser(new MavenParser());
    }
}