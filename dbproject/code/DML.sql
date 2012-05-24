INSERT INTO proj_customer VALUE("Eric","Soros","8121 Elmwood Dr.", "Kirtland","OH", "44094", "440-622-6166","esoros@gmail.com");
INSERT INTO proj_customer VALUE("Test","Test", "1234 Parkway Dr.", "Mentor", "OH", "44094", "440-123-1234", "test@test.com");
INSERT INTO proj_customer VALUE("Test", "TestAdmin", "0000 Main Street", "Kent", "OH", "44124", "440-123-1234", "testadmin@test.com");

INSERT INTO proj_login VALUE("esoros@gmail.com", "5f4dcc3b5aa765d61d8327deb882cf99");
INSERT INTO proj_login VALUE("test@test.com", "098f6bcd4621d373cade4e832627b4f6");
INSERT INTO proj_login VALUE("testadmin@test.com", "098f6bcd4621d373cade4e832627b4f6");

INSERT INTO proj_admin VALUE("esoros@gmail.com");
INSERT INTO proj_admin VALUE("testadmin@test.com");

INSERT INTO proj_author VALUE(NULL,"Kurt", "Vonnegut");

INSERT INTO proj_book VALUE("0-385-31208-3","Slaughterhouse 5",1,186,"1969",9.99);
INSERT INTO proj_book VALUE("0-385-28089-0", "Breakfast of Champions", 1, 300, "1971", 5.99);

INSERT INTO proj_stock VALUE("0-385-31208-3", 10);
INSERT INTO proj_stock VALUE("0-385-28089-0", 5);


INSERT INTO proj_orders VALUE("000000000000", "esoros@gmail.com", CURRENT_DATE());

INSERT INTO proj_order_items VALUE("000000000000", "0-385-31208-3", 2, 18.99);
INSERT INTO proj_order_items VALUE("000000000000", "0-385-28089-0", 1, 5.99);
