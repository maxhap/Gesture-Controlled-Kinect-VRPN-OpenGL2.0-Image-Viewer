/*
	Templated from Rob Aspin code
*/
#include "stdafx.h"
#include "Node.h"
using namespace std;

Node::Node()
{
}

Node::~Node()
{
	for( Nodes::iterator i = _paChildren.begin(); i != _paChildren.end(); i++ ) 
	{
		( *i )->unreferenceObject();		
	}

	_paChildren.clear();
}

void Node::addChild( Node* pChild )
{
	if( pChild && !isParent( pChild ) && !isChild( pChild ) )
	{
		_paChildren.push_back( pChild );
		pChild->_paParents.push_back( this );
		pChild->referenceObject();
	}
}

void Node::removeChild( Node* pChild )
{
	if( pChild )
	{
		Nodes::iterator i = find( _paChildren.begin(), _paChildren.end(), pChild );

		if( i != _paChildren.end() )
		{
			Nodes::iterator pit = find( pChild->_paParents.begin(), pChild->_paParents.end(), this );
			
			if( pit != pChild->_paParents.end() ) 
			{
				pChild->_paParents.erase( pit );
			}

			_paChildren.erase( i );
			pChild->unreferenceObject();
		}
	}
}

unsigned int Node::indexOfChild( Node* pChild )
{
	Nodes::iterator i = find( _paChildren.begin(), _paChildren.end(), pChild );

	if( i != _paChildren.end() ) 
	{ 
		return i - _paChildren.begin();
	}

	return 0;
}

unsigned int Node::numberOfChildren()
{
	return ( unsigned int ) _paChildren.size();
}

unsigned int Node::indexOfParent( Node* pParent )
{
	Nodes::iterator i = find( _paParents.begin(), _paParents.end(), pParent );

	if( i != _paParents.end() )
	{
		return i - _paParents.begin();
	}

	return 0;
}

unsigned int Node::numberOfParents()
{
	return ( unsigned int ) _paParents.size();
}

Node* Node::getParent( unsigned int uiIndex )
{
	if( uiIndex < numberOfParents() ) 
	{
		return _paParents[uiIndex];
	}

	return 0;
}

Node* Node::getChild( unsigned int uiIndex )
{
	if( uiIndex<numberOfChildren() ) 
	{
		return _paChildren[uiIndex];
	}

	return 0;
}

bool Node::isParent(Node *pNode)
{
	if( find( _paParents.begin(), _paParents.end(), pNode ) != _paParents.end() ) 
	{
		return true;
	}

	return false;
}

bool Node::isChild( Node *pNode )
{
	if( find( _paChildren.begin(), _paChildren.end(), pNode) != _paChildren.end() )
	{
		return true;
	}

	return false;
}
