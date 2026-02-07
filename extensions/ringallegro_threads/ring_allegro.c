#include "ring.h"

/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */

#define ALLEGRO_NO_MAGIC_MAIN

#include <allegro5/allegro.h>
RING_FUNC(ring_al_exit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	exit(0);
}

VM *globalVM ;

int al_usr_main(int argc, char **argv)
{
	ring_vm_runcode(globalVM,"al_game_start()");	
	exit(0);
	return 0;
}

RING_FUNC(ring_al_run_main)
{
	globalVM = (VM *) pPointer ;
	al_run_main(globalVM->pRingState->nArgc,globalVM->pRingState->pArgv,al_usr_main);	
}

RING_FUNC(ring_al_init)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_init());
}


RING_FUNC(ring_al_create_config)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_create_config(),"ALLEGRO_CONFIG");
}


RING_FUNC(ring_al_destroy_config)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_config((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"));
}


RING_FUNC(ring_al_load_config_file)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_load_config_file(RING_API_GETSTRING(1)),"ALLEGRO_CONFIG");
}


RING_FUNC(ring_al_load_config_file_f)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_load_config_file_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")),"ALLEGRO_CONFIG");
}


RING_FUNC(ring_al_save_config_file)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_save_config_file(RING_API_GETSTRING(1),(ALLEGRO_CONFIG *) RING_API_GETCPOINTER(2,"ALLEGRO_CONFIG")));
}


RING_FUNC(ring_al_save_config_file_f)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_save_config_file_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),(ALLEGRO_CONFIG *) RING_API_GETCPOINTER(2,"ALLEGRO_CONFIG")));
}


RING_FUNC(ring_al_add_config_section)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_add_config_section((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_al_add_config_comment)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_add_config_comment((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_al_get_config_value)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_config_value((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_al_set_config_value)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_config_value((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4));
}


RING_FUNC(ring_al_get_first_config_section)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_first_config_section((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),(ALLEGRO_CONFIG_SECTION **) RING_API_GETCPOINTER2POINTER(2,"ALLEGRO_CONFIG_SECTION")));
}


RING_FUNC(ring_al_get_next_config_section)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_next_config_section((ALLEGRO_CONFIG_SECTION **) RING_API_GETCPOINTER2POINTER(1,"ALLEGRO_CONFIG_SECTION")));
}


RING_FUNC(ring_al_get_first_config_entry)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_first_config_entry((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),RING_API_GETSTRING(2),(ALLEGRO_CONFIG_ENTRY **) RING_API_GETCPOINTER2POINTER(3,"ALLEGRO_CONFIG_ENTRY")));
}


RING_FUNC(ring_al_get_next_config_entry)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_next_config_entry((ALLEGRO_CONFIG_ENTRY **) RING_API_GETCPOINTER2POINTER(1,"ALLEGRO_CONFIG_ENTRY")));
}


RING_FUNC(ring_al_merge_config)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_merge_config((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),(ALLEGRO_CONFIG *) RING_API_GETCPOINTER(2,"ALLEGRO_CONFIG")),"ALLEGRO_CONFIG");
}


RING_FUNC(ring_al_merge_config_into)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_merge_config_into((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),(ALLEGRO_CONFIG *) RING_API_GETCPOINTER(2,"ALLEGRO_CONFIG"));
}


RING_FUNC(ring_al_get_time)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_time());
}


RING_FUNC(ring_al_init_timeout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_init_timeout((ALLEGRO_TIMEOUT *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMEOUT"), (double ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_al_rest)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_rest( (double ) RING_API_GETNUMBER(1));
}

void *al_func_thread(ALLEGRO_THREAD *thread, void *pPointer)
{
	List *pList;
	VM *pVM;
	const char *cStr;
	pList = (List *) pPointer ;
	pVM = (VM *) ring_list_getpointer(pList,2);
	cStr = ring_list_getstring(pList,1);
	ring_vm_runcodefromthread(pVM,cStr);	
	ring_list_delete(pList);
	return NULL;
}

void *al_func_detached_thread(void *pPointer)
{
	return al_func_thread(NULL,pPointer);
}

RING_FUNC(ring_al_create_thread)
{
	ALLEGRO_THREAD *pThread;
	List *pList;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}	
	pList = ring_list_new(0);
	ring_list_addstring(pList,RING_API_GETSTRING(1));
	ring_list_addpointer(pList,pPointer);
	ring_vm_mutexfunctions((VM *) pPointer,al_create_mutex,al_lock_mutex,al_unlock_mutex,al_destroy_mutex);
	pThread = al_create_thread(al_func_thread, pList);
	al_start_thread(pThread);
	RING_API_RETCPOINTER(pThread,"ALLEGRO_THREAD");	
}

RING_FUNC(ring_al_run_detached_thread)
{
	List *pList;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}	
	pList = ring_list_new(0);
	ring_list_addstring(pList,RING_API_GETSTRING(1));
	ring_list_addpointer(pList,pPointer);
	ring_vm_mutexfunctions((VM *) pPointer,al_create_mutex,al_lock_mutex,al_unlock_mutex,al_destroy_mutex);
	al_run_detached_thread(al_func_detached_thread, pList);
}

RING_FUNC(ring_al_start_thread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_start_thread((ALLEGRO_THREAD *) RING_API_GETCPOINTER(1,"ALLEGRO_THREAD"));
}


RING_FUNC(ring_al_join_thread)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_join_thread((ALLEGRO_THREAD *) RING_API_GETCPOINTER(1,"ALLEGRO_THREAD"),(void **) RING_API_GETCPOINTER2POINTER(2,"void"));
}


RING_FUNC(ring_al_set_thread_should_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_thread_should_stop((ALLEGRO_THREAD *) RING_API_GETCPOINTER(1,"ALLEGRO_THREAD"));
}


RING_FUNC(ring_al_get_thread_should_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_thread_should_stop((ALLEGRO_THREAD *) RING_API_GETCPOINTER(1,"ALLEGRO_THREAD")));
}


RING_FUNC(ring_al_destroy_thread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_thread((ALLEGRO_THREAD *) RING_API_GETCPOINTER(1,"ALLEGRO_THREAD"));
}


RING_FUNC(ring_al_create_mutex)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_create_mutex(),"ALLEGRO_MUTEX");
}


RING_FUNC(ring_al_create_mutex_recursive)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_create_mutex_recursive(),"ALLEGRO_MUTEX");
}


RING_FUNC(ring_al_lock_mutex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_lock_mutex((ALLEGRO_MUTEX *) RING_API_GETCPOINTER(1,"ALLEGRO_MUTEX"));
}


RING_FUNC(ring_al_unlock_mutex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_unlock_mutex((ALLEGRO_MUTEX *) RING_API_GETCPOINTER(1,"ALLEGRO_MUTEX"));
}


RING_FUNC(ring_al_destroy_mutex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_mutex((ALLEGRO_MUTEX *) RING_API_GETCPOINTER(1,"ALLEGRO_MUTEX"));
}


RING_FUNC(ring_al_create_cond)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_create_cond(),"ALLEGRO_COND");
}


RING_FUNC(ring_al_destroy_cond)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_cond((ALLEGRO_COND *) RING_API_GETCPOINTER(1,"ALLEGRO_COND"));
}


RING_FUNC(ring_al_wait_cond)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_wait_cond((ALLEGRO_COND *) RING_API_GETCPOINTER(1,"ALLEGRO_COND"),(ALLEGRO_MUTEX *) RING_API_GETCPOINTER(2,"ALLEGRO_MUTEX"));
}


RING_FUNC(ring_al_wait_cond_until)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_wait_cond_until((ALLEGRO_COND *) RING_API_GETCPOINTER(1,"ALLEGRO_COND"),(ALLEGRO_MUTEX *) RING_API_GETCPOINTER(2,"ALLEGRO_MUTEX"),(ALLEGRO_TIMEOUT *) RING_API_GETCPOINTER(3,"ALLEGRO_TIMEOUT")));
}


RING_FUNC(ring_al_broadcast_cond)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_broadcast_cond((ALLEGRO_COND *) RING_API_GETCPOINTER(1,"ALLEGRO_COND"));
}


RING_FUNC(ring_al_signal_cond)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_signal_cond((ALLEGRO_COND *) RING_API_GETCPOINTER(1,"ALLEGRO_COND"));
}

RING_LIBINIT
{
	RING_API_REGISTER("al_exit",ring_al_exit);
	RING_API_REGISTER("al_run_main",ring_al_run_main);
	RING_API_REGISTER("al_init",ring_al_init);
	RING_API_REGISTER("al_create_config",ring_al_create_config);
	RING_API_REGISTER("al_destroy_config",ring_al_destroy_config);
	RING_API_REGISTER("al_load_config_file",ring_al_load_config_file);
	RING_API_REGISTER("al_load_config_file_f",ring_al_load_config_file_f);
	RING_API_REGISTER("al_save_config_file",ring_al_save_config_file);
	RING_API_REGISTER("al_save_config_file_f",ring_al_save_config_file_f);
	RING_API_REGISTER("al_add_config_section",ring_al_add_config_section);
	RING_API_REGISTER("al_add_config_comment",ring_al_add_config_comment);
	RING_API_REGISTER("al_get_config_value",ring_al_get_config_value);
	RING_API_REGISTER("al_set_config_value",ring_al_set_config_value);
	RING_API_REGISTER("al_get_first_config_section",ring_al_get_first_config_section);
	RING_API_REGISTER("al_get_next_config_section",ring_al_get_next_config_section);
	RING_API_REGISTER("al_get_first_config_entry",ring_al_get_first_config_entry);
	RING_API_REGISTER("al_get_next_config_entry",ring_al_get_next_config_entry);
	RING_API_REGISTER("al_merge_config",ring_al_merge_config);
	RING_API_REGISTER("al_merge_config_into",ring_al_merge_config_into);
	RING_API_REGISTER("al_get_time",ring_al_get_time);
	RING_API_REGISTER("al_init_timeout",ring_al_init_timeout);
	RING_API_REGISTER("al_rest",ring_al_rest);
	RING_API_REGISTER("al_create_thread",ring_al_create_thread);
	RING_API_REGISTER("al_run_detached_thread",ring_al_run_detached_thread);
	RING_API_REGISTER("al_start_thread",ring_al_start_thread);
	RING_API_REGISTER("al_join_thread",ring_al_join_thread);
	RING_API_REGISTER("al_set_thread_should_stop",ring_al_set_thread_should_stop);
	RING_API_REGISTER("al_get_thread_should_stop",ring_al_get_thread_should_stop);
	RING_API_REGISTER("al_destroy_thread",ring_al_destroy_thread);
	RING_API_REGISTER("al_create_mutex",ring_al_create_mutex);
	RING_API_REGISTER("al_create_mutex_recursive",ring_al_create_mutex_recursive);
	RING_API_REGISTER("al_lock_mutex",ring_al_lock_mutex);
	RING_API_REGISTER("al_unlock_mutex",ring_al_unlock_mutex);
	RING_API_REGISTER("al_destroy_mutex",ring_al_destroy_mutex);
	RING_API_REGISTER("al_create_cond",ring_al_create_cond);
	RING_API_REGISTER("al_destroy_cond",ring_al_destroy_cond);
	RING_API_REGISTER("al_wait_cond",ring_al_wait_cond);
	RING_API_REGISTER("al_wait_cond_until",ring_al_wait_cond_until);
	RING_API_REGISTER("al_broadcast_cond",ring_al_broadcast_cond);
	RING_API_REGISTER("al_signal_cond",ring_al_signal_cond);
}
