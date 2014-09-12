#ifndef _DRAWABLElIST_
#define _DRAWABLElIST_

#include "stdafx.h"
#include "DrawableObject.h"
#include "DrawableListItem.h"
#include "MaxRectangle.h"

typedef vector<DrawableListItem*> ItemList; 

using namespace std;

class DrawableList : public DrawableObject
{

public:

	DrawableList();
	virtual ~DrawableList();

	void AddItem( DrawableListItem* pItem );	
	void SelectColision( MaxRectangle* pColisionBox );
	void UnselectAllItems();
	void ProceedActivations();
	virtual void Draw();

protected:

	ItemList* _pDrawablelListItems;

};

#endif