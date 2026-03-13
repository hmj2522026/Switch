#include "Node.h"

Node::~Node()
{
	for (Node* node : m_children)
	{
		delete node;
		node = nullptr;
	}
	m_children.clear();
}

void Node::Start_()
{
	Start();
	Update();
	m_updateFunc = &Node::Update;
}

void Node::Destroy()
{
	if (!m_parent) { return; }

	if (m_isDestroyed) { return; }

	m_isDestroyed = true;

	m_parent->RemoveChild(this);
}

void Node::AddChild(Node* node)
{
	node->SetParent(this);

	m_children.push_back(node);

	node->TreeLoad();
}

void Node::RemoveChild(Node* node)
{
	m_removeChildren.push_back(node);
}

void Node::TreeLoad()
{
	if (!m_isLoaded)
	{
		Load();
		m_isLoaded = true;
	}

	for (Node* node : m_children)
	{
		node->TreeLoad();
	}
}

void Node::TreeRelease()
{
	if (m_isLoaded)
	{
		Release();
		m_isLoaded = false;
	}

	for (Node* node : m_children)
	{
		node->TreeRelease();
	}
}

void Node::TreeUpdate()
{
	(this->*m_updateFunc)();

	for (Node* node : m_children)
	{
		node->TreeUpdate();
	}

	for (Node* node : m_removeChildren)
	{
		node->TreeRelease();
		m_children.remove(node);
		delete node;
		node = nullptr;
	}
	m_removeChildren.clear();
}

void Node::TreeDraw()
{
	Draw();

	for (Node* node : m_children)
	{
		node->TreeDraw();
	}
}
