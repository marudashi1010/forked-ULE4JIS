// Ule4Jis.h : PROJECT_NAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"		// ���C�� �V���{��


// Ule4JisApp:
// ���̃N���X�̎����ɂ��ẮAUle4Jis.cpp ���Q�Ƃ��Ă��������B
//

class Ule4JisApp : public CWinApp
{
public:
	Ule4JisApp();

// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern Ule4JisApp theApp;