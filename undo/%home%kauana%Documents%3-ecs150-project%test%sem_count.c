Vim�UnDo� �{˱c` o�ڮ�$�q�ZhD�<V�uQU�z�   U                 $       $   $   $    Z�y�    _�                    K        ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   K   M   V              �   K   M   U    5�_�                    L       ����                                                                                                                                                                                                                                                                                                                                                             Z��    �   K   M   V              puts("1);5�_�                    M       ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   M   O   V    �   M   N   V    5�_�                    N       ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   M   O   W              puts("1");5�_�                    P       ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   P   R   W    �   P   Q   W    5�_�      	              Q       ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   P   R   X              puts("1");5�_�      
           	   Q       ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   P   R   X              puts("2");5�_�   	              
   R       ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   R   T   X    �   R   S   X    5�_�   
                 S       ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   R   T   Y              puts("1");5�_�                    S       ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   R   T   Y              puts("2");5�_�                    S       ����                                                                                                                                                                                                                                                                                                                                                             Z��    �   R   T   Y              puts("3");5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             Z�a�    �      !   Z                      �      !   Y    5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             Z�a�    �      !   Z                      puts("boots")5�_�                   -       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�    �   -   /   [                      �   -   /   Z    5�_�                    .       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�    �   -   /   [                      puts("pants")5�_�                    .       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�     �   -   .                          puts("pants");5�_�                    .       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�    �   .   0   Z    �   .   /   Z    5�_�                    0       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�     �   0   2   [    �   0   1   [    5�_�                    1       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�     �   0   2   \                      puts("pants");5�_�                    1       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�     �   0   2          $                puts("bye from t1");5�_�                    "       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�     �   "   $   \    �   "   #   \    5�_�                    #       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�     �   "   $   ]              puts("bye from t1");5�_�                    #       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�     �   "   $   ]              puts("bye from t0");5�_�                    #       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�    �   "   $   ]              puts("bye from t1");5�_�                    2       ����                                                                                                                                                                                                                                                                                                                                                             Z�cm     �   1   2                  puts("bye from t1");5�_�                    0        ����                                                                                                                                                                                                                                                                                                                                                             Z�cn     �   /   0                          puts("pants");5�_�                    #       ����                                                                                                                                                                                                                                                                                                                                                             Z�cp     �   "   #                  puts("bye from t2");5�_�                              ����                                                                                                                                                                                                                                                                                                                                                             Z�cq   	 �                                 puts("boots");5�_�      !               S        ����                                                                                                                                                                                                                                                                                                                                                             Z�g�     �   R   S                  puts("4");5�_�       "           !   Q        ����                                                                                                                                                                                                                                                                                                                                                             Z�g�     �   P   Q                  puts("3");5�_�   !   #           "   N       ����                                                                                                                                                                                                                                                                                                                                                             Z�g�     �   M   N                  puts("2");5�_�   "   $           #   L        ����                                                                                                                                                                                                                                                                                                                                                             Z�g�   
 �   K   L                  puts("1");5�_�   #               $           ����                                                                                                                                                                                                                                                                                                                                       U           V        Z�y�    �   S   U          
	return 0;�   Q   S          	sem_destroy(t.sem2);�   P   R          	sem_destroy(t.sem1);�   N   P          	pthread_join(tid[1], NULL);�   M   O          	pthread_join(tid[0], NULL);�   K   M          ,	pthread_create(&tid[1], NULL, thread2, &t);�   J   L          ,	pthread_create(&tid[0], NULL, thread1, &t);�   H   J          	t.sem2 = sem_create(0);�   G   I          	t.sem1 = sem_create(0);�   F   H          		t.x = 0;�   E   G          	t.maxcount = maxcount;�   C   E          		maxcount = get_argv(argv[1]);�   B   D          	if (argc > 1)�   @   B          	pthread_t tid[2];�   ?   A          	size_t maxcount = MAXCOUNT;�   >   @          	struct test3 t;�   9   ;          	return ret;�   8   :          	}�   7   9          
		exit(1);�   6   8          		perror("strtol");�   5   7          *	if (ret == LONG_MIN || ret == LONG_MAX) {�   4   6          &	long int ret = strtol(argv, NULL, 0);�   /   1          	return NULL;�   -   /          	}�   ,   .          		sem_up(t->sem2);�   +   -          (		printf("thread 1, x = %zu\n", t->x++);�   *   ,          		sem_down(t->sem1);�   )   +          	while (t->x < t->maxcount) {�   '   )          &	struct test3 *t = (struct test3*)arg;�   "   $          	return NULL;�       "          	}�      !          		sem_down(t->sem2);�                 		sem_up(t->sem1);�                (		printf("thread 2, x = %zu\n", t->x++);�                	while (t->x < t->maxcount) {�                &	struct test3 *t = (struct test3*)arg;�                	size_t maxcount;�                
	size_t x;�                	sem_t sem2;�                	sem_t sem1;5�_�                    -       ����                                                                                                                                                                                                                                                                                                                                                             Z�a�     �   -   .   Z    �   ,   .   Z      4		printf("threadpthread_self 1, x = %zu\n", t->x++);5�_�                    K        ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   K   L   U    �   J   L   U      -	&pthread_create(&tid[0], NULL, thread1, &t);5�_�                     K        ����                                                                                                                                                                                                                                                                                                                                                             Z��     �   K   L   U    �   J   L   U      -	&pthread_create(&tid[0], NULL, thread1, &t);5��