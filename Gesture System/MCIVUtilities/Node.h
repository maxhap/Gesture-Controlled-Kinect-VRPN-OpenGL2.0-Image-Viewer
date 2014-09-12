#pragma once

#include "stdafx.h"
#include "Referenced.h"
#include "MCIVUtilitiesDEFS.h"

typedef std::deque<class Node*> Nodes;

class MCIVUTILITIES_DLL_DEF Node : public Referenced
{
public:
	Node();

	void addChild( Node* pChild );
	void removeChild( Node* pChild );

	unsigned int indexOfChild( Node* pChild );
	unsigned int numberOfChildren();
	unsigned int indexOfParent( Node* pParent );
	unsigned int numberOfParents();

	Node* getParent( unsigned int uiIndex );
	Node* getChild( unsigned int uiIndex );

	bool isParent( Node* pNode );
	bool isChild( Node* pNode );

protected:
	~Node();

private:
	Nodes _paParents;
	Nodes _paChildren;
};

