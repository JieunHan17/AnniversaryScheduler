/*
2019 1�б� �����ͺ��̽� ������ ������
������ �� �� ��������Ʈ - �ҽ��ڵ�
201521046 õ����
201720805 ������
�ε��� �� -
1. ���� ����
2. �ѱ����� (ini���� ����, �ڵ� �߰�) -> �ᱹ ����� ó����
3. scanf ���� �� ����� �Է� �ȵ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <my_global.h>
#include <WinSock2.h>
#include<mysql.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#pragma comment(lib, "libmysql.lib")
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "root"
#define DB_NAME "dbproject2"
// #define DB_NAME "dbproject"
#define CHOP(x) x[strlen(x) - 1] = ' ' 

// mysql���� �ѱ� �޴� �� alter table cats convert to character set utf8;

int main(void)
{
	MYSQL *connection = NULL, conn; // ���� ����ü conn ���� �� �ʱ�ȭ
	MYSQL_RES *sql_result; // ���� ��� 
	MYSQL_ROW sql_row; // ���� ��� �� ��
	int query_stat; // ���� �� �޾Ҵ��� ���

					// �Է��ϴ� ����
	char query[500];

	//����ڰ� �Է��ϴ� �޴���ȣ
	char menu[10];
	char submenu[10];


	/*********************************************Ŀ�ؼ� �� �ѱ� ���� ����**************************************************************/
	mysql_init(&conn); // Ŀ�ؼ� �ʱ�ȭ

					   //Ŀ�ؼ� Ȯ��  
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char *)NULL, 0);

	//Ŀ�ؼ� ���� 
	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}

	//�ѱ� �ȱ����� test ���� - 
	//query_stat = mysql_query(connection, "set names euckr");
	//if (query_stat != 0) // ���� 
	//{
	//   fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
	//   return 1;
	//}
	/*********************************************Ŀ�ؼ� �� �ѱ� ���� ����**************************************************************/


	/*
	//test ����  - ���� ������/ ���� ���/ ���� ��� free
	query_stat = mysql_query(connection, "select * from  object");
	if (query_stat != 0) // ����
	{
	fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
	return 1;
	}

	//���� �������� ���� ���
	sql_result = mysql_store_result(connection);

	//printf("�����̸� ����ī�װ� ����Ƽ�ܿ��� ����\n");
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
	printf("%s   %s   %s   %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
	}

	mysql_free_result(sql_result);
	///////////////////////////////////////////////////////////////////
	*/


	// attribute �� �Է¹��� 

	/*
	// ������ ����
	printf("���� �Է��� ���ϴ� �̸��� �߰��ؼ� ������ ���� �Է��ϼ���\n");
	printf("���� - select * from object where objectName = '�Է°�';\n");
	fgets(query, 500, stdin);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
	fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
	return 1;
	}

	//���� �������� ���� ���
	sql_result = mysql_store_result(connection);

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
	printf("%s   %s   %s   %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
	}


	mysql_free_result(sql_result);

	*/

	while (1)
	{
		printf("�������~\n��ģ�е� Ȯ���� ������ ����� ����Ρ� �� ���Ű� ȯ���մϴ�\n\n");

		printf("==========================================\n");
		printf("��� ����\n");
		printf("1.���� ��� Ȯ��\n");
		printf("2.��󺰷� ����Ͽ� �� �� Ȯ��\n");
		printf("3.ģ�е� üũ\n");
		printf("4.���� ��õ\n");
		printf("5.����� ���\n");
		printf("6.����� �˻�\n"); // 1. ����� ���� ��� �����ְ�, �ű⼭ ���� �� ����Ͽ� ���� ��ü ���� ���̱�
		printf("**���� ����� 0�� �Է��ϼ���**\n");
		printf("==========================================\n");
		printf("\n���Ͻô� ����� ��ȣ�� �Է����ּ��� : ");
		fgets(menu, 10, stdin);

		printf("\n\n");


		if (menu[0] == '1') {
			printf("1. ��ü�� ���ؼ� �˻��ϱ�\n");
			printf("2. ��¥�� ���ؼ� �˻��ϱ�\n");

			printf("�޴� ��ȣ�� �Է��ϼ��� :");
			fgets(submenu, 10, stdin);

			if (submenu[0] == '1') {
				//1. ��ü�� ���ؼ� �˻�
				printf("\n1-1\n������� ��ü�� �Ʒ��� ��ɹ��� ���� �Է��ϼ���.  ex) father, mother \n");
				printf("���� : create view e1 as select eventName, objectName, giftName, giveYear from Event, giftlog where event.objectName = '�Է°�' and event.eventId = giftlog.eventId;\n");
				printf("�Է��ϼ��� : ");
				fgets(query, 500, stdin);


				// �Է¹��� ������ �����ͺ��̽��� ����.
				query_stat = mysql_query(connection, query);
				if (query_stat != 0)
				{
					//����üũ
					fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
					return 1;
				}

				// 2. �Է��� ��ü�� �ش��ϴ� ������� �����.
				query_stat = mysql_query(connection, "select distinct eventName from e1;");
				if (query_stat != 0)
				{
					//����üũ
					fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
					return 1;
				}
				//���� �������� ���� ��� 
				sql_result = mysql_store_result(connection);
				printf("\n����� ��� :\n");
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
				{

					printf("%s\n", sql_row[0]);
				}

				mysql_free_result(sql_result);

				//3. ����ڰ� ��µ� ����� �߿��� ���ϴ� ������� �Է���. 
				printf("\n\n������ ������ ����߿��� Ȯ���ϰ� ���� ������� �Է��ϼ���. \n");
				printf("�������� : select giftname, giveyear from e1 where eventName = '�Է°�';\n");
				printf("�Է��ϼ��� : ");
				fgets(query, 500, stdin);

				query_stat = mysql_query(connection, query);
				if (query_stat != 0)
				{
					//����üũ
					fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
					return 1;
				}
				//���� �������� ���� ��� 
				sql_result = mysql_store_result(connection);
				printf("\n\nì����� ����      ������ �� ��\n");
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
				{
					printf("%s			 %s\n", sql_row[0], sql_row[1]);
				}

				mysql_free_result(sql_result);

				// �Է¹��� ������ �����ͺ��̽��� ����.
				query_stat = mysql_query(connection, "drop view e1;");
				if (query_stat != 0)
				{
					//����üũ
					fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
					return 1;
				}

				//1-1��� �� 

			}
			else {
				if (submenu[0] == '2') {
					//��¥�� ���ؼ� �˻�
					printf("\n1-2\n������� ��¥�� �Ʒ��� ��ɹ��� ���� �Է��ϼ���.\n");
					printf("���� : create view e1 as select month, day, eventName, giftName, giveYear from Event, giftlog where event.month = �Է°�(���� ��) and event.day = �Է°�(���� ��) and event.eventId = giftlog.eventId;\n");
					printf("�Է��ϼ��� : ");
					fgets(query, 500, stdin);


					// �Է¹��� ������ �����ͺ��̽��� ����.
					query_stat = mysql_query(connection, query);
					if (query_stat != 0)
					{
						//����üũ
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}

					// 2. �Է��� ��¥�� �ش��ϴ� ������� �����.
					query_stat = mysql_query(connection, "select distinct eventName from e1;");
					if (query_stat != 0)
					{
						//����üũ
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}
					//���� �������� ���� ��� 
					sql_result = mysql_store_result(connection);
					printf("\n����� ��� :\n");
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{

						printf("%s\n", sql_row[0]);
					}

					mysql_free_result(sql_result);

					//3. ����ڰ� ��µ� ����� �߿��� ���ϴ� ������� �Է���. 
					printf("\n\n������ ������ ����߿��� Ȯ���ϰ� ���� ������� �Է��ϼ���. \n");
					printf("�������� : select giftname, giveyear from e1 where eventName = '�Է°�';\n");
					printf("�Է��ϼ��� : ");
					fgets(query, 500, stdin);

					query_stat = mysql_query(connection, query);
					if (query_stat != 0)
					{
						//����üũ
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}
					//���� �������� ���� ��� 
					sql_result = mysql_store_result(connection);
					printf("\n\nì����� ����      ������ �� ��\n");
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						printf("%s			 %s\n", sql_row[0], sql_row[1]);
					}

					mysql_free_result(sql_result);

					// �Է¹��� ������ �����ͺ��̽��� ����.
					query_stat = mysql_query(connection, "drop view e1;");
					if (query_stat != 0)
					{
						//����üũ
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}

					//1-2��� �� 
				}
				else {
					printf("���� ����\n");
				}
			}


		}
		else {
			if (menu[0] == '2') {
				//�Է¹��� ��ü�� �������� ì����� ����Ͽ� �⵵ ���� �󸶳� ����� ���հ� Ȯ��
				printf("\n2\nƯ���� ��ü�� �������� ì����� ����ϰ� �⵵���� �󸶳� ����� �� �հ踦 Ȯ���غ���\n");
				printf("�������� : select objectname, eventID, giveyear, sum(price) from ol1 where objectname = '�Է°�' group by objectName, eventID, giveyear;\n");
				printf("�Է��ϼ��� : ");
				fgets(query, 500, stdin);


				// �Է¹��� ������ �����ͺ��̽��� ����.
				query_stat = mysql_query(connection, query);
				if (query_stat != 0)
				{
					//����üũ
					fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
					return 1;
				}
				//���� �������� ���� ��� 
				sql_result = mysql_store_result(connection);
				printf("\n��ü	    ����Ϲ�ȣ			�⵵			�� ����\n");
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
				{

					printf("%s		%s			%s			%s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
				}

				mysql_free_result(sql_result);

				//2�� ��� �� 

			}
			else {
				if (menu[0] == '3') {
					//������ �� Ƚ���� ���� �м��� Ư�������� ģ�е� ���� ����
					printf("\n3\n������ ����� ���\n");
					// �Է¹��� ������ �����ͺ��̽��� ����.
					query_stat = mysql_query(connection, "select distinct objectname from ol1");
					if (query_stat != 0)
					{
						//����üũ
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}
					//���� �������� ���� ��� 
					sql_result = mysql_store_result(connection);
					printf("\n��ü\n");
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{

						printf("%s\n", sql_row[0]);
					}

					mysql_free_result(sql_result);
					printf("\n");

					//ol1 ���� ì��� �� Ƚ��
					query_stat = mysql_query(connection, "select count(eventID) from ol1");
					if (query_stat != 0)
					{
						//����üũ
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}
					//���� �������� ���� ��� 
					sql_result = mysql_store_result(connection);

					int total;
					//printf("\n��ü\n");
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						//printf("%s\n", sql_row[0]);
						total = atoi(sql_row[0]);
						//printf("��Ż %d %s\n", total, sql_row[0]);
					}
					//printf("%dfffff\n", total);
					mysql_free_result(sql_result);

					printf("ģ�е��� Ȯ���ϰ� ���� ��ü�� �̸��� �������ÿ� ���� �Է��ϼ���.\n");
					printf("�������� :select count(giftname) from ol1 where objectname ='�Է°�';\n");
					printf("�Է��ϼ��� : ");
					fgets(query, 500, stdin);

					// �Է¹��� ������ �����ͺ��̽��� ����.
					query_stat = mysql_query(connection, query);
					if (query_stat != 0)
					{
						//����üũ
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}
					//���� �������� ���� ��� 
					sql_result = mysql_store_result(connection);
					int num;
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						num = atoi(sql_row[0]);
					}

					mysql_free_result(sql_result);

					int default = 50; // �⺻ ģ�е� �� 
					printf("\n\n�����ش� ��ü���� ģ�е��� %.2f%% �Դϴ�.����\n", (float)num / total * 100 + default);


					//3�� ��� �� 
				}
				else {
					if (menu[0] == '4') {
						printf("\n4\n���� ��õ�ޱ�\n");
						// �Է¹��� ������ �����ͺ��̽��� ����.
						query_stat = mysql_query(connection, "select distinct event, object from recommend");
						if (query_stat != 0)
						{
							//����üũ
							fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
							return 1;
						}
						//���� �������� ���� ��� 
						sql_result = mysql_store_result(connection);
						printf("\n<��õ �����-��� ���>\n");
						while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						{
							printf("%s		%s\n", sql_row[0], sql_row[1]);
						}

						mysql_free_result(sql_result);


						//4-1 �����-��� ��Ͽ��� ��õ�ޱ� ���ϴ� ����ϰ� ��� �Է��ϱ�
						printf("\n��õ�ޱ� ���ϴ� �����, ���, ����� ������ �������ÿ� ���� �Է��ϼ���. ex)���� - male, female, both");
						printf("\n�������� :select agerange, giftname from recommend where event = '�Է°�' and object = '�Է°�' and gender = '�Է°�';\n");
						printf("�Է��ϼ��� : ");
						fgets(query, 500, stdin);

						query_stat = mysql_query(connection, query);
						if (query_stat != 0)
						{
							//����üũ
							fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
							return 1;
						}
						//���� �������� ���� ��� 
						sql_result = mysql_store_result(connection);

						printf("\n<�Է��Ͻ� ����ϰ� ��� ���� ���ɺ��� ��õ�帮�� ���� ����Դϴ�.>\n");
						printf("���ɴ�		������\n");
						while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						{
							printf("%s		%s\n", sql_row[0], sql_row[1]);
						}

						mysql_free_result(sql_result);


					}
					else {
						if (menu[0] == '5') {
							//5-1 Ʈ���� ����- ����� �������� �Է�
							printf("\n5\n���ο� ������� ����ϼ���\n\n");
							printf("�߰��ϰ��� �ϴ� ����� ������ �������ÿ� ���� �Է��ϼ���\n");
							printf("�������� : create trigger t1 after insert on object for each row begin insert into event(year, month, day, eventname, objectname, eventcategory) values (�⵵, ��, ��, '������̸�', new.objectname, '����� ī�װ�'); end\n");
							printf("�Է��ϼ��� : ");
							fgets(query, 500, stdin);



							// �Է¹��� ������ �����ͺ��̽��� ����.
							query_stat = mysql_query(connection, query);
							if (query_stat != 0)
							{
								//����üũ
								fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
								return 1;
							}

							//5-2 ����� ��ü ���� �Է��ϱ� 
							printf("���ο� ��ü ������ �Է��ϼ���.\n");
							printf("�������� : insert into object values ('�̸�', ����, '����', '����');\n");
							printf("�Է��ϼ��� : ");
							fgets(query, 500, stdin);

							// �Է¹��� ������ �����ͺ��̽��� ����.
							query_stat = mysql_query(connection, query);
							if (query_stat != 0)
							{
								//����üũ
								fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
								return 1;
							}

							// Ʈ���� ������ 
							query_stat = mysql_query(connection, "drop trigger t1;");
							if (query_stat != 0)
							{
								//����üũ
								fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
								return 1;
							}

							//5�� ��

							printf("������� ��ϵǾ����ϴ�!\n\n");

						}
						else {
							if (menu[0] == '6') {
								//����ڰ� �ñ����ϴ� ����� ���� ����
								printf("\n6\n����� ���\n");
								// �Է¹��� ������ �����ͺ��̽��� ����.
								query_stat = mysql_query(connection, "select eventName from Event");
								if (query_stat != 0)
								{
									//����üũ
									fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
									return 1;
								}
								//���� �������� ���� ��� 
								sql_result = mysql_store_result(connection);
								printf("\n����ڰ� ������ ����� �̸�\n");
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
								{

									printf("%s\n", sql_row[0]);
								}
								mysql_free_result(sql_result);
								printf("\n");

								//����ڰ� �ñ����ϴ� ����� �̸��� �Է¹ް�, �̿� ���� Event ���̺��� ������
								printf("\n\n������ ������ ��� �߿��� Ȯ���ϰ� ���� ������� �Ʒ� ���ÿ� ���� �Է��ϼ���. \n");
								printf("�������� : select * from Event where eventName = '�Է°�';\n");
								printf("�Է��ϼ��� : ");
								fgets(query, 500, stdin);
								// �Է¹��� ������ �����ͺ��̽��� ����.
								query_stat = mysql_query(connection, query);
								if (query_stat != 0)
								{
									//����üũ
									fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
									return 1;
								}
								//���� �������� ���� ��� 
								sql_result = mysql_store_result(connection);
								printf("\neventID      ����      ��      ��      ����� �̸�      ��ü �̸�      ����� ī�װ�\n");
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
								{

									printf("%s   	    %s	%s	%s	%s	  %s	        %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3], sql_row[4], sql_row[5], sql_row[6]);
								}
								mysql_free_result(sql_result);
								printf("\n");
								char choice[15];

								//������� ���� ���ο� ���� ���� ����Ͽ� ���� Object ���̺��� ������
								printf("�� ����Ͽ� ���� ��ü ������ �� ���������� Ȯ���ϰ� �����Ű���?\n");
								printf("����(Y �Ǵ� N) : ");

								fgets(choice, 10, stdin);
								//printf("**\n");
								if (choice[0] == 'Y') {
									printf("\n\n�׷��� ������ ����� ���� ��ü �̸��� �־� �Ʒ� ���ÿ� �°� �Է��ϼ���. \n");
									printf("�������� : select * from Object where objectName = '�Է°�';\n");
									printf("�Է��ϼ��� : ");
									fgets(query, 500, stdin);
									// �Է¹��� ������ �����ͺ��̽��� ����.
									query_stat = mysql_query(connection, query);
									if (query_stat != 0)
									{
										//����üũ
										fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
										return 1;
									}
									//���� �������� ���� ��� 
									sql_result = mysql_store_result(connection);
									printf("\n��ü �̸�      ����      ����      ����\n");
									while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
									{

										printf("%s           %s      %s      %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
									}
									mysql_free_result(sql_result);
									printf("\n");
								}
								else {
									//printf("�ȵȴ�\n");
								}

								//6�� ��� ��
							}
							else
							{
								if (menu[0] == '0') {
									break;
								}
								else
									printf("��ȣ�� �ٽ� �Է����ּ���\n");
							}
						}
					}
				}
			}
		}

		//	menu[0] = 'null';
		//submenu[0] = 'null';

		printf("\n\n\n\n");
	} // while ��


	printf("\n���񽺰� ����Ǿ����ϴ�\n\n");



	mysql_close(connection);
}