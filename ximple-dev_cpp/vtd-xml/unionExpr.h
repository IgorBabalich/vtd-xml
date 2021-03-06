/* 
* Copyright (C) 2002-2015 XimpleWare, info@ximpleware.com
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/
/*VTD-XML is protected by US patent 7133857, 7260652, an 7761459*/
#pragma once
#ifndef UNION_EXPR_H
#define UNION_EXPR_H
#include "expr.h"
#include "intHash.h"
//#include "xpathParser.tab.hh"

namespace com_ximpleware{
	class UnionExpr: public Expr{
	public:
		UnionExpr(Expr *e);
		~UnionExpr();
		bool evalBoolean(VTDNav *vn);
		double evalNumber(VTDNav *vn);
		int evalNodeSet(VTDNav *vn);
		UCSChar* evalString(VTDNav *vn);

		void reset(VTDNav *vn);
		void toString(UCSChar *string);

		bool isNumerical();
		bool isNodeSet();
		bool isString();
		bool isBoolean();

		bool requireContextSize();
		void setContextSize(int size);

		void setPosition(int pos);
		int adjust(int n);	
		UnionExpr *current;
		UnionExpr *next;
		Expr *fe;

		bool isFinal();
		
		void markCacheable();
		void markCacheable2();
		void clearCache();
	private:
		bool isUnique_une(int i){
			return ih->isUnique(i);
		}
		
		int evalState;
		/*FastIntBuffer *fib;*/
		IntHash *ih;
	};
}

#endif
