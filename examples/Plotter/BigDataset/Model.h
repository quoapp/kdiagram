/**
 * Copyright (C) 2001-2015 Klaralvdalens Datakonsult AB.  All rights reserved.
 *
 * This file is part of the KD Chart library.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MODEL_H
#define MODEL_H

#include <QAbstractItemModel>
#include <QTimer>
#include <QVector>

class Model : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum Function {
        SineFunction = 0,
        TriangleFunction,
        SquareFunction,
        NoiseFunction,
        OneDivSineFunction,
        SineOneDivFunction
    };
    Model();

    int columnCount( const QModelIndex& parent ) const;
    int rowCount( const QModelIndex& parent ) const;

    QModelIndex index( int row, int column, const QModelIndex& parent ) const;
    QModelIndex parent( const QModelIndex& index ) const;

    QVariant data( const QModelIndex& index, int role ) const;

    void setFunction( Function f );

    void appendPoints( int numPoints );

public slots:
    void setRunning( bool );

private slots:
    void appendPoint();

private:
    qreal nextFunctionValue();

    qreal m_x;
    Function m_function;
    QVector< qreal > m_data;
    QTimer m_appendTimer;
};

#endif
