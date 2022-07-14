/*
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
#ifndef BUILDERGENERATOR_H
#define BUILDERGENERATOR_H

#include "builderglobals.h"
#include "common/common.h"
#include "services/builder/ioutputparser.h"

#include <QWidget>
#include <QMenu>

namespace dpfservice {
class BuilderGenerator : public Generator
{
    Q_OBJECT
public:
    BuilderGenerator(){}
    virtual ~BuilderGenerator(){}

    virtual void getMenuCommand(BuildCommandInfo &info, const BuildMenuType buildMenuType) {
        Q_UNUSED(info)
        Q_UNUSED(buildMenuType)
    }

    virtual void appendOutputParser(std::unique_ptr<IOutputParser>& outputParser) {
        Q_UNUSED(outputParser)
    }
};

} // namespace dpfservice

#endif // BUILDERGENERATOR_H
