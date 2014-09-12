#include "stdafx.h"
#include "DrawableList.h"

DrawableList::DrawableList() : DrawableObject()
{
	_pDrawablelListItems = new ItemList();
}

DrawableList::~DrawableList()
{
	if( _pDrawablelListItems ) delete _pDrawablelListItems;
}

void DrawableList::AddItem( DrawableListItem* pItem )
{	
	pItem->SetIsSelected(  false );
	_pDrawablelListItems->push_back( pItem );
}

void DrawableList::Draw()
{
	DrawableObject::Draw();

	for( ItemList::iterator i = _pDrawablelListItems->begin(); i != _pDrawablelListItems->end(); i++ )
	{
		( *i )->Draw();
	}
}

void DrawableList::SelectColision( MaxRectangle* pColisionBox )
{
	DrawableListItem* pCollidedObject = NULL;

	for( ItemList::iterator i = _pDrawablelListItems->begin(); i != _pDrawablelListItems->end(); i++ )
	{
		if( ( *i )->SelectColision( pColisionBox ) ) 
		{ 
			pCollidedObject = ( *i );
			break;
		}		
	}

	UnselectAllItems();

	if( pCollidedObject != NULL )
	{
		pCollidedObject->SetIsSelected( true );
	}
}

void DrawableList::UnselectAllItems()
{
	for( ItemList::iterator i = _pDrawablelListItems->begin(); i != _pDrawablelListItems->end(); i++ )
	{
		 ( *i )->SetIsSelected( false );
	}
}

void DrawableList::ProceedActivations()
{
	for( ItemList::iterator i = _pDrawablelListItems->begin(); i != _pDrawablelListItems->end(); i++ )
	{
		( *i )->ProceedActivation();
	}
}
