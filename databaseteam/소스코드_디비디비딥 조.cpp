/*
2019 1학기 데이터베이스 변광준 교수님
디비디비딥 조 조 팀프로젝트 - 소스코드
201521046 천혜림
201720805 한지은
부딪힌 점 -
1. 연동 문제
2. 한글지원 (ini파일 수정, 코드 추가) -> 결국 영어로 처리함
3. scanf 숫자 값 제대로 입력 안됨
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

// mysql에서 한글 받는 거 alter table cats convert to character set utf8;

int main(void)
{
	MYSQL *connection = NULL, conn; // 연결 구조체 conn 선언 및 초기화
	MYSQL_RES *sql_result; // 쿼리 결과 
	MYSQL_ROW sql_row; // 쿼리 결과 한 줄
	int query_stat; // 쿼리 잘 받았는지 결과

					// 입력하는 쿼리
	char query[500];

	//사용자가 입력하는 메뉴번호
	char menu[10];
	char submenu[10];


	/*********************************************커넥션 및 한글 깨짐 방지**************************************************************/
	mysql_init(&conn); // 커넥션 초기화

					   //커넥션 확인  
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char *)NULL, 0);

	//커넥션 에러 
	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}

	//한글 안깨지나 test 쿼리 - 
	//query_stat = mysql_query(connection, "set names euckr");
	//if (query_stat != 0) // 오류 
	//{
	//   fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
	//   return 1;
	//}
	/*********************************************커넥션 및 한글 깨짐 방지**************************************************************/


	/*
	//test 쿼리  - 쿼리 보내고/ 쿼리 출력/ 쿼리 결과 free
	query_stat = mysql_query(connection, "select * from  object");
	if (query_stat != 0) // 오류
	{
	fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
	return 1;
	}

	//위에 쿼리문에 대한 결과
	sql_result = mysql_store_result(connection);

	//printf("선물이름 선물카테고리 기프티콘여부 수제\n");
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
	printf("%s   %s   %s   %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
	}

	mysql_free_result(sql_result);
	///////////////////////////////////////////////////////////////////
	*/


	// attribute 값 입력받음 

	/*
	// 쿼리문 복붙
	printf("쿼리 입력해 원하는 이름을 추가해서 쿼리를 따라 입력하세요\n");
	printf("예시 - select * from object where objectName = '입력값';\n");
	fgets(query, 500, stdin);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
	fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
	return 1;
	}

	//위에 쿼리문에 대한 결과
	sql_result = mysql_store_result(connection);

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
	printf("%s   %s   %s   %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
	}


	mysql_free_result(sql_result);

	*/

	while (1)
	{
		printf("어서오세요~\n★친밀도 확인이 가능한 기념일 가계부★ 에 오신걸 환영합니다\n\n");

		printf("==========================================\n");
		printf("기능 목차\n");
		printf("1.선물 기록 확인\n");
		printf("2.대상별로 기념일에 쓴 돈 확인\n");
		printf("3.친밀도 체크\n");
		printf("4.선물 추천\n");
		printf("5.기념일 등록\n");
		printf("6.기념일 검색\n"); // 1. 기념일 먼저 목록 보여주고, 거기서 고른후 고른 기념일에 대해 주체 정보 보이기
		printf("**서비스 종료는 0을 입력하세요**\n");
		printf("==========================================\n");
		printf("\n원하시는 기능의 번호를 입력해주세요 : ");
		fgets(menu, 10, stdin);

		printf("\n\n");


		if (menu[0] == '1') {
			printf("1. 주체에 대해서 검색하기\n");
			printf("2. 날짜에 대해서 검색하기\n");

			printf("메뉴 번호를 입력하세요 :");
			fgets(submenu, 10, stdin);

			if (submenu[0] == '1') {
				//1. 주체에 대해서 검색
				printf("\n1-1\n기념일의 주체를 아래의 명령문에 맞춰 입력하세요.  ex) father, mother \n");
				printf("쿼리 : create view e1 as select eventName, objectName, giftName, giveYear from Event, giftlog where event.objectName = '입력값' and event.eventId = giftlog.eventId;\n");
				printf("입력하세요 : ");
				fgets(query, 500, stdin);


				// 입력받은 쿼리를 데이터베이스로 보냄.
				query_stat = mysql_query(connection, query);
				if (query_stat != 0)
				{
					//에러체크
					fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
					return 1;
				}

				// 2. 입력한 주체에 해당하는 기념일을 출력함.
				query_stat = mysql_query(connection, "select distinct eventName from e1;");
				if (query_stat != 0)
				{
					//에러체크
					fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
					return 1;
				}
				//위에 쿼리문에 대한 결과 
				sql_result = mysql_store_result(connection);
				printf("\n기념일 목록 :\n");
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
				{

					printf("%s\n", sql_row[0]);
				}

				mysql_free_result(sql_result);

				//3. 사용자가 출력된 기념일 중에서 원하는 기념일을 입력함. 
				printf("\n\n위에서 보여진 목록중에서 확인하고 싶은 기념일을 입력하세요. \n");
				printf("쿼리예시 : select giftname, giveyear from e1 where eventName = '입력값';\n");
				printf("입력하세요 : ");
				fgets(query, 500, stdin);

				query_stat = mysql_query(connection, query);
				if (query_stat != 0)
				{
					//에러체크
					fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
					return 1;
				}
				//위에 쿼리문에 대한 결과 
				sql_result = mysql_store_result(connection);
				printf("\n\n챙겨줬던 선물      선물을 준 해\n");
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
				{
					printf("%s			 %s\n", sql_row[0], sql_row[1]);
				}

				mysql_free_result(sql_result);

				// 입력받은 쿼리를 데이터베이스로 보냄.
				query_stat = mysql_query(connection, "drop view e1;");
				if (query_stat != 0)
				{
					//에러체크
					fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
					return 1;
				}

				//1-1기능 끝 

			}
			else {
				if (submenu[0] == '2') {
					//날짜에 대해서 검색
					printf("\n1-2\n기념일의 날짜를 아래의 명령문에 맞춰 입력하세요.\n");
					printf("쿼리 : create view e1 as select month, day, eventName, giftName, giveYear from Event, giftlog where event.month = 입력값(숫자 월) and event.day = 입력값(숫자 일) and event.eventId = giftlog.eventId;\n");
					printf("입력하세요 : ");
					fgets(query, 500, stdin);


					// 입력받은 쿼리를 데이터베이스로 보냄.
					query_stat = mysql_query(connection, query);
					if (query_stat != 0)
					{
						//에러체크
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}

					// 2. 입력한 날짜에 해당하는 기념일을 출력함.
					query_stat = mysql_query(connection, "select distinct eventName from e1;");
					if (query_stat != 0)
					{
						//에러체크
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}
					//위에 쿼리문에 대한 결과 
					sql_result = mysql_store_result(connection);
					printf("\n기념일 목록 :\n");
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{

						printf("%s\n", sql_row[0]);
					}

					mysql_free_result(sql_result);

					//3. 사용자가 출력된 기념일 중에서 원하는 기념일을 입력함. 
					printf("\n\n위에서 보여진 목록중에서 확인하고 싶은 기념일을 입력하세요. \n");
					printf("쿼리예시 : select giftname, giveyear from e1 where eventName = '입력값';\n");
					printf("입력하세요 : ");
					fgets(query, 500, stdin);

					query_stat = mysql_query(connection, query);
					if (query_stat != 0)
					{
						//에러체크
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}
					//위에 쿼리문에 대한 결과 
					sql_result = mysql_store_result(connection);
					printf("\n\n챙겨줬던 선물      선물을 준 해\n");
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						printf("%s			 %s\n", sql_row[0], sql_row[1]);
					}

					mysql_free_result(sql_result);

					// 입력받은 쿼리를 데이터베이스로 보냄.
					query_stat = mysql_query(connection, "drop view e1;");
					if (query_stat != 0)
					{
						//에러체크
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}

					//1-2기능 끝 
				}
				else {
					printf("숫자 오류\n");
				}
			}


		}
		else {
			if (menu[0] == '2') {
				//입력받은 주체를 기준으로 챙겼었던 기념일에 년도 마다 얼마나 썼는지 총합계 확인
				printf("\n2\n특정한 주체를 기준으로 챙겼었던 기념일과 년도마다 얼마나 썼는지 총 합계를 확인해보자\n");
				printf("쿼리예시 : select objectname, eventID, giveyear, sum(price) from ol1 where objectname = '입력값' group by objectName, eventID, giveyear;\n");
				printf("입력하세요 : ");
				fgets(query, 500, stdin);


				// 입력받은 쿼리를 데이터베이스로 보냄.
				query_stat = mysql_query(connection, query);
				if (query_stat != 0)
				{
					//에러체크
					fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
					return 1;
				}
				//위에 쿼리문에 대한 결과 
				sql_result = mysql_store_result(connection);
				printf("\n주체	    기념일번호			년도			총 가격\n");
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
				{

					printf("%s		%s			%s			%s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
				}

				mysql_free_result(sql_result);

				//2번 기능 끝 

			}
			else {
				if (menu[0] == '3') {
					//선물을 준 횟수를 토대로 분석한 특정대상과의 친밀도 정보 제공
					printf("\n3\n선물을 줬었던 대상\n");
					// 입력받은 쿼리를 데이터베이스로 보냄.
					query_stat = mysql_query(connection, "select distinct objectname from ol1");
					if (query_stat != 0)
					{
						//에러체크
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}
					//위에 쿼리문에 대한 결과 
					sql_result = mysql_store_result(connection);
					printf("\n주체\n");
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{

						printf("%s\n", sql_row[0]);
					}

					mysql_free_result(sql_result);
					printf("\n");

					//ol1 선물 챙겼던 총 횟수
					query_stat = mysql_query(connection, "select count(eventID) from ol1");
					if (query_stat != 0)
					{
						//에러체크
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}
					//위에 쿼리문에 대한 결과 
					sql_result = mysql_store_result(connection);

					int total;
					//printf("\n주체\n");
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						//printf("%s\n", sql_row[0]);
						total = atoi(sql_row[0]);
						//printf("토탈 %d %s\n", total, sql_row[0]);
					}
					//printf("%dfffff\n", total);
					mysql_free_result(sql_result);

					printf("친밀도를 확인하고 싶은 주체의 이름을 쿼리예시에 맞춰 입력하세요.\n");
					printf("쿼리예시 :select count(giftname) from ol1 where objectname ='입력값';\n");
					printf("입력하세요 : ");
					fgets(query, 500, stdin);

					// 입력받은 쿼리를 데이터베이스로 보냄.
					query_stat = mysql_query(connection, query);
					if (query_stat != 0)
					{
						//에러체크
						fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
						return 1;
					}
					//위에 쿼리문에 대한 결과 
					sql_result = mysql_store_result(connection);
					int num;
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						num = atoi(sql_row[0]);
					}

					mysql_free_result(sql_result);

					int default = 50; // 기본 친밀도 값 
					printf("\n\n♥♡해당 주체와의 친밀도는 %.2f%% 입니다.♡♥\n", (float)num / total * 100 + default);


					//3번 기능 끝 
				}
				else {
					if (menu[0] == '4') {
						printf("\n4\n선물 추천받기\n");
						// 입력받은 쿼리를 데이터베이스로 보냄.
						query_stat = mysql_query(connection, "select distinct event, object from recommend");
						if (query_stat != 0)
						{
							//에러체크
							fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
							return 1;
						}
						//위에 쿼리문에 대한 결과 
						sql_result = mysql_store_result(connection);
						printf("\n<추천 기념일-대상 목록>\n");
						while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						{
							printf("%s		%s\n", sql_row[0], sql_row[1]);
						}

						mysql_free_result(sql_result);


						//4-1 기념일-대상 목록에서 추천받기 원하는 기념일과 대상 입력하기
						printf("\n추천받기 원하는 기념일, 대상, 대상의 성별을 쿼리예시에 맞춰 입력하세요. ex)성별 - male, female, both");
						printf("\n쿼리예시 :select agerange, giftname from recommend where event = '입력값' and object = '입력값' and gender = '입력값';\n");
						printf("입력하세요 : ");
						fgets(query, 500, stdin);

						query_stat = mysql_query(connection, query);
						if (query_stat != 0)
						{
							//에러체크
							fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
							return 1;
						}
						//위에 쿼리문에 대한 결과 
						sql_result = mysql_store_result(connection);

						printf("\n<입력하신 기념일과 대상에 대해 연령별로 추천드리는 선물 목록입니다.>\n");
						printf("연령대		선물명\n");
						while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						{
							printf("%s		%s\n", sql_row[0], sql_row[1]);
						}

						mysql_free_result(sql_result);


					}
					else {
						if (menu[0] == '5') {
							//5-1 트리거 생성- 기념일 정보부터 입력
							printf("\n5\n새로운 기념일을 등록하세요\n\n");
							printf("추가하고자 하는 기념일 정보를 쿼리예시에 맞춰 입력하세요\n");
							printf("쿼리예시 : create trigger t1 after insert on object for each row begin insert into event(year, month, day, eventname, objectname, eventcategory) values (년도, 월, 일, '기념일이름', new.objectname, '기념일 카테고리'); end\n");
							printf("입력하세요 : ");
							fgets(query, 500, stdin);



							// 입력받은 쿼리를 데이터베이스로 보냄.
							query_stat = mysql_query(connection, query);
							if (query_stat != 0)
							{
								//에러체크
								fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
								return 1;
							}

							//5-2 기념일 주체 정보 입력하기 
							printf("새로운 주체 정보를 입력하세요.\n");
							printf("쿼리예시 : insert into object values ('이름', 나이, '성별', '관계');\n");
							printf("입력하세요 : ");
							fgets(query, 500, stdin);

							// 입력받은 쿼리를 데이터베이스로 보냄.
							query_stat = mysql_query(connection, query);
							if (query_stat != 0)
							{
								//에러체크
								fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
								return 1;
							}

							// 트리거 날리기 
							query_stat = mysql_query(connection, "drop trigger t1;");
							if (query_stat != 0)
							{
								//에러체크
								fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
								return 1;
							}

							//5번 끝

							printf("기념일이 등록되었습니다!\n\n");

						}
						else {
							if (menu[0] == '6') {
								//사용자가 궁금해하는 기념일 정보 제공
								printf("\n6\n기념일 목록\n");
								// 입력받은 쿼리를 데이터베이스로 보냄.
								query_stat = mysql_query(connection, "select eventName from Event");
								if (query_stat != 0)
								{
									//에러체크
									fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
									return 1;
								}
								//위에 쿼리문에 대한 결과 
								sql_result = mysql_store_result(connection);
								printf("\n사용자가 저장한 기념일 이름\n");
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
								{

									printf("%s\n", sql_row[0]);
								}
								mysql_free_result(sql_result);
								printf("\n");

								//사용자가 궁금해하는 기념일 이름을 입력받고, 이에 대한 Event 테이블을 보여줌
								printf("\n\n위에서 보여진 목록 중에서 확인하고 싶은 기념일을 아래 예시와 같이 입력하세요. \n");
								printf("쿼리예시 : select * from Event where eventName = '입력값';\n");
								printf("입력하세요 : ");
								fgets(query, 500, stdin);
								// 입력받은 쿼리를 데이터베이스로 보냄.
								query_stat = mysql_query(connection, query);
								if (query_stat != 0)
								{
									//에러체크
									fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
									return 1;
								}
								//위에 쿼리문에 대한 결과 
								sql_result = mysql_store_result(connection);
								printf("\neventID      연도      월      일      기념일 이름      주체 이름      기념일 카테고리\n");
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
								{

									printf("%s   	    %s	%s	%s	%s	  %s	        %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3], sql_row[4], sql_row[5], sql_row[6]);
								}
								mysql_free_result(sql_result);
								printf("\n");
								char choice[15];

								//사용자의 응답 여부에 따라 위의 기념일에 대한 Object 테이블을 보여줌
								printf("이 기념일에 대한 주체 정보를 더 세부적으로 확인하고 싶으신가요?\n");
								printf("선택(Y 또는 N) : ");

								fgets(choice, 10, stdin);
								//printf("**\n");
								if (choice[0] == 'Y') {
									printf("\n\n그러면 위에서 결과로 나온 주체 이름을 넣어 아래 예시에 맞게 입력하세요. \n");
									printf("쿼리예시 : select * from Object where objectName = '입력값';\n");
									printf("입력하세요 : ");
									fgets(query, 500, stdin);
									// 입력받은 쿼리를 데이터베이스로 보냄.
									query_stat = mysql_query(connection, query);
									if (query_stat != 0)
									{
										//에러체크
										fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
										return 1;
									}
									//위에 쿼리문에 대한 결과 
									sql_result = mysql_store_result(connection);
									printf("\n주체 이름      나이      성별      관계\n");
									while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
									{

										printf("%s           %s      %s      %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
									}
									mysql_free_result(sql_result);
									printf("\n");
								}
								else {
									//printf("안된다\n");
								}

								//6번 기능 끝
							}
							else
							{
								if (menu[0] == '0') {
									break;
								}
								else
									printf("번호를 다시 입력해주세요\n");
							}
						}
					}
				}
			}
		}

		//	menu[0] = 'null';
		//submenu[0] = 'null';

		printf("\n\n\n\n");
	} // while 끝


	printf("\n서비스가 종료되었습니다\n\n");



	mysql_close(connection);
}