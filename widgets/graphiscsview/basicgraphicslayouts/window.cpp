/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "window.h"
#include "layoutitem.h"

#include <QGraphicsLinearLayout>
#include <QGraphicsGridLayout>

Window::Window(QGraphicsWidget *parent) : QGraphicsWidget(parent, Qt::Window)
{
//! [0]
    // QGraphicsLinearLayout处理Qt::Horizontal和Qt::Vertical两个方向的排版布局，默认为Qt::Horizontal
    QGraphicsLinearLayout *windowLayout = new QGraphicsLinearLayout(Qt::Vertical);
    QGraphicsLinearLayout *linear = new QGraphicsLinearLayout(windowLayout);
    LayoutItem *item = new LayoutItem;//调用自定义类LayoutItem
    linear->addItem(item);
    linear->setStretchFactor(item, 1);
//! [0]

//! [1]
    item = new LayoutItem;
    linear->addItem(item);
    /*
     用一句话来表示我对setStretchFactor(list，1)的理解吧：就是说，如果设置了可伸缩控件，
     则该控件对应的窗口，在进行缩放的时候，该控件不会进行伸缩。。（伸缩：被拉大了，被拉小了）。。。
     而且要说明一下，在一开始，所有的部件都默认指定为可伸缩的。。一旦有部件指定为可伸缩部件后，
     其他部件自动设置为不可伸缩部件。。
    */
    linear->setStretchFactor(item, 3);
    windowLayout->addItem(linear);
//! [1]

//! [2]
    QGraphicsGridLayout *grid = new QGraphicsGridLayout(windowLayout);
    item = new LayoutItem;
    grid->addItem(item, 0, 0, 4, 1);
    item = new LayoutItem;
    item->setMaximumHeight(item->minimumHeight());
    grid->addItem(item, 0, 1, 2, 1, Qt::AlignVCenter);
    item = new LayoutItem;
    item->setMaximumHeight(item->minimumHeight());
    grid->addItem(item, 2, 1, 2, 1, Qt::AlignVCenter);
    item = new LayoutItem;
    grid->addItem(item, 0, 2);
    item = new LayoutItem;
    grid->addItem(item, 1, 2);
    item = new LayoutItem;
    grid->addItem(item, 2, 2);
    item = new LayoutItem;
    grid->addItem(item, 3, 2);
    windowLayout->addItem(grid);
//! [2]

//! [3]
    setLayout(windowLayout);
    setWindowTitle(tr("Basic Graphics Layouts Example"));
//! [3]

}
