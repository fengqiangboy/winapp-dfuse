
// helloView.cpp : ChelloView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "hello.h"
#endif

#include "helloDoc.h"
#include "helloView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ChelloView

IMPLEMENT_DYNCREATE(ChelloView, CView)

BEGIN_MESSAGE_MAP(ChelloView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &ChelloView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ChelloView 构造/析构

ChelloView::ChelloView()
{
	// TODO: 在此处添加构造代码

}

ChelloView::~ChelloView()
{
}

BOOL ChelloView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// ChelloView 绘制

void ChelloView::OnDraw(CDC* /*pDC*/)
{
	ChelloDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// ChelloView 打印


void ChelloView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL ChelloView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void ChelloView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void ChelloView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void ChelloView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void ChelloView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ChelloView 诊断

#ifdef _DEBUG
void ChelloView::AssertValid() const
{
	CView::AssertValid();
}

void ChelloView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ChelloDoc* ChelloView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ChelloDoc)));
	return (ChelloDoc*)m_pDocument;
}
#endif //_DEBUG


// ChelloView 消息处理程序
