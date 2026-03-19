#include "Block.h"
#include "BoxCollider.h"
#include "DxLib.h"

Block::Block(Vector2 pos,Tag tag) :
	Actor2D(pos,tag,Rigidbody2D::BodyType::Static),
	m_sprite(0)
{
	m_collider = new BoxCollider(HitBoxSize);
}

void Block::Load()
{
	Actor2D::Load();
	if (m_tag == Tag::Block)
	{
		m_sprite = LoadGraph("Resource/block.png");
	}
	else if (m_tag == Tag::BlockBreakable)
	{
		m_sprite = LoadGraph("Resource/block_breakable.png");
	}
}

void Block::Release()
{
	Actor2D::Release();

	if (m_sprite)
	{
		DeleteGraph(m_sprite);
	}
}

void Block::Draw()
{
	DrawRotaGraph(static_cast<int>(m_transform.position.x), static_cast<int>(m_transform.position.y), 1.0f, 0.0f, m_sprite, true);
}

void Block::OnCollisionEnter(const Actor2D* other)
{
	if (m_tag == Tag::BlockBreakable && other->GetTag() == Tag::Punch)
	{
		Destroy();
	}
}
