#include"head.h"
SCOPE HEAD_SCOPE = NULL;//��������ͷ���ָ��
SCOPE CUR_SCOPE = NULL;//��ǰ������/ջ��ָ��
inline void Push_Scope(char *scope_name) {//��������ջ
	CUR_SCOPE->next = (SCOPE)malloc(sizeof(SCOPE_NODE));
	CUR_SCOPE->next->prior = CUR_SCOPE;
	CUR_SCOPE = CUR_SCOPE->next;
	strcpy(CUR_SCOPE->name , scope_name);
	CUR_SCOPE->var = (VAR_TREE)malloc(sizeof(VAR_NODE));
	CUR_SCOPE->var->next = NULL;
	CUR_SCOPE->next = NULL;
}
inline void Pop_Scope(void) {//�������ջ
	CUR_SCOPE = CUR_SCOPE->prior;
}
void Push_Var(char *var_name, int var_value) {//�����±���
	VAR_TREE p = CUR_SCOPE->var;
	while (p->next)
		p = p->next;
	p->next = (VAR_TREE)malloc(sizeof(VAR_NODE));
	p = p->next;
	strcpy(p->name , var_name);
	p->value = var_value;
	p->next = NULL;
}
int Get_Var(char *var_name) {//��ȡ����ֵ
	SCOPE pscope = CUR_SCOPE;
	VAR_TREE pvar = CUR_SCOPE->var;
	while (1) {
		while (pvar->next) {
			pvar = pvar->next;
			if (!strcmp(pvar->name , var_name))
				return pvar->value;
		}
		pscope = pscope->prior;
		if (pscope->prior == NULL)return 0;
		pvar = pscope->var;
	}
}
void Set_Var(char *var_name, int var_value) {//�ı����ֵ
	SCOPE pscope = CUR_SCOPE;
	VAR_TREE pvar = CUR_SCOPE->var;
	while (1) {
		while (pvar->next) {
			pvar = pvar->next;
			if (!strcmp(pvar->name , var_name))
				pvar->value = var_value;
		}
		pscope = pscope->prior;
		if (pscope->prior == NULL)break;
		pvar = pscope->var;
	}
}