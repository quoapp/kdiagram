/**
 * Copyright (C) 2001-2015 Klaralvdalens Datakonsult AB.  All rights reserved.
 *
 * This file is part of the KGantt library.
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

#ifndef KGANTTCONSTRAINTMODEL_P_H
#define KGANTTCONSTRAINTMODEL_P_H

#include "kganttconstraintmodel.h"

#include <QList>
#include <QMultiHash>
#include <QPersistentModelIndex>

namespace KGantt {
    class ConstraintModel::Private {
    public:
        Private();

        void addConstraintToIndex( const QModelIndex& idx, const Constraint& c );
        void removeConstraintFromIndex( const QModelIndex& idx,  const Constraint& c );

        typedef QMultiHash<QPersistentModelIndex,Constraint> IndexType;

        QList<Constraint> constraints;
        IndexType indexMap;
    };
}

#endif /* KGANTTCONSTRAINTMODEL_P_H */

