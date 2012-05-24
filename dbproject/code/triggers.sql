-- This trigger will change the stock levels any time a books is added to order Items. 

DROP TRIGGER IF EXISTS update_stock;
DELIMITER $$

CREATE TRIGGER update_stock AFTER INSERT ON proj_order_items
FOR EACH ROW BEGIN
	UPDATE proj_stock SET qty = (qty - NEW.qty) where ISBN = new.ISBN;
END$$

