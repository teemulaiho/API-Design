#include "Collider.h"

Collider::Collider() : m_rect(0,0,0,0)
{
}

Collider::Collider(const Collider& rhs) : m_rect(rhs.m_rect)
{
}

Collider::Collider(int p_x, int p_y, int p_w, int p_h) : m_rect(p_x,p_y,p_w,p_h)
{
}

void Collider::SetBounds(int p_x, int p_y, int p_w, int p_h)
{
	m_rect.SetBounds(p_x, p_y, p_w, p_h);
}
