-- MySQL dump 10.13  Distrib 8.1.0, for Win64 (x86_64)
--
-- Host: localhost    Database: metro_system
-- ------------------------------------------------------
-- Server version	8.1.0

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `belong`
--

DROP TABLE IF EXISTS `belong`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `belong` (
  `Eno` int NOT NULL,
  `Lno` int NOT NULL,
  PRIMARY KEY (`Eno`,`Lno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `belong`
--

LOCK TABLES `belong` WRITE;
/*!40000 ALTER TABLE `belong` DISABLE KEYS */;
INSERT INTO `belong` VALUES (0,1),(1,2),(2,1),(3,2),(4,1),(5,2),(6,2),(7,1),(8,2),(9,1),(10,1),(11,2),(12,2),(13,1),(14,1),(15,2),(16,2),(17,1),(18,1),(19,2),(20,2),(21,1),(22,1),(23,2),(24,2),(25,1),(26,2),(27,1),(28,1),(29,2),(30,1),(31,2),(32,1),(33,2),(34,1),(35,2),(36,2),(37,1),(38,1),(39,2),(40,2),(41,1),(42,1),(43,2),(44,2),(45,1),(46,2),(47,1),(48,2),(49,1),(50,2),(51,1),(52,2),(53,1),(54,3),(55,4),(56,4),(57,3),(58,3),(59,4),(60,4),(61,3),(62,3),(63,4),(64,3),(65,4),(66,4),(67,3),(68,3),(69,4),(70,4),(71,3),(72,3),(73,4),(74,4),(75,3),(76,4),(77,3),(78,3),(79,4),(80,4),(81,3),(82,3),(83,4),(84,4),(85,3),(86,3),(87,4),(88,4),(89,3),(90,3),(91,4),(92,4),(93,3),(94,3),(95,4),(96,4),(97,3),(98,3),(99,4),(100,3),(101,4),(102,4),(103,3),(104,3),(105,4),(106,4),(107,3),(108,3),(109,4),(110,4),(111,3),(112,6),(112,7),(113,5),(113,8),(114,5),(114,8),(115,6),(115,7),(116,6),(116,7),(117,5),(117,8),(118,5),(119,6),(120,6),(121,5),(122,5),(123,6),(124,6),(125,5),(126,5),(126,8),(127,6),(127,7),(128,5),(128,8),(129,6),(129,7),(130,6),(130,7),(131,5),(131,8),(132,5),(132,8),(133,6),(133,7),(134,6),(134,7),(135,5),(135,8),(136,5),(136,8),(137,6),(137,7),(138,6),(139,5),(140,6),(141,5),(142,5),(143,6),(144,6),(145,5),(146,5),(147,6),(148,6),(149,5),(150,5),(151,6),(152,6),(153,5),(154,5),(155,6),(156,5),(157,6),(158,5),(159,6),(160,6),(161,5),(162,5),(163,6),(164,6),(165,5),(166,6),(167,5),(168,8),(169,7),(170,8),(171,7),(172,7),(173,8),(174,8),(175,7),(176,7),(177,8),(178,7),(179,8),(180,8),(181,7),(182,7),(183,8),(184,8),(185,7),(186,7),(187,8),(188,8),(189,7),(190,7),(191,8),(192,8),(193,7),(194,7),(195,8),(196,8),(197,7),(198,7),(199,8),(200,8),(201,7),(202,11),(202,12),(203,9),(203,10),(204,9),(204,10),(205,11),(206,11),(206,12),(207,9),(207,10),(208,11),(208,12),(209,9),(209,10),(210,9),(210,10),(211,11),(211,12),(212,11),(212,12),(213,9),(213,10),(214,9),(214,10),(215,11),(215,12),(216,11),(216,12),(217,9),(217,10),(218,9),(218,10),(219,11),(219,12),(220,11),(220,12),(221,9),(221,10),(222,9),(222,10),(223,11),(223,12),(224,11),(224,12),(225,9),(225,10),(226,9),(226,10),(227,11),(227,12),(228,9),(228,10),(229,11),(229,12),(230,9),(230,10),(231,11),(231,12),(232,9),(232,10),(233,11),(233,12),(234,9),(234,10),(235,11),(235,12),(236,9),(236,10),(237,11),(237,12),(238,11),(238,12),(239,9),(239,10),(240,9),(240,10),(241,11),(241,12),(242,11),(242,12),(243,9),(243,10),(244,9),(244,10),(245,11),(245,12),(246,11),(246,12),(247,9),(247,10),(248,9),(248,10),(249,11),(249,12),(250,11),(250,12),(251,9),(251,10),(252,9),(252,10),(253,11),(253,12),(254,11),(254,12),(255,9),(255,10),(256,9),(256,10),(257,11),(257,12),(258,11),(259,9),(260,9),(261,11),(262,12),(263,10),(264,10),(265,12),(266,12),(267,10),(268,10),(269,12),(270,12),(271,10),(272,10),(273,12),(274,12),(275,10),(276,9),(277,11);
/*!40000 ALTER TABLE `belong` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `costtime`
--

DROP TABLE IF EXISTS `costtime`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `costtime` (
  `Cline` int NOT NULL,
  `Ctarget` int NOT NULL,
  `Ctime` time DEFAULT NULL,
  PRIMARY KEY (`Cline`,`Ctarget`),
  KEY `Cost_time_index` (`Ctime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `costtime`
--

LOCK TABLES `costtime` WRITE;
/*!40000 ALTER TABLE `costtime` DISABLE KEYS */;
INSERT INTO `costtime` VALUES (5,23,'00:00:00'),(6,82,'00:00:00'),(9,109,'00:00:00'),(10,109,'00:00:00'),(11,125,'00:00:00'),(12,132,'00:00:00'),(5,62,'00:02:00'),(11,124,'00:02:00'),(12,131,'00:02:00'),(6,81,'00:03:00'),(5,61,'00:04:00'),(9,108,'00:04:00'),(10,108,'00:04:00'),(6,80,'00:06:00'),(11,123,'00:06:00'),(12,130,'00:06:00'),(5,60,'00:07:00'),(9,107,'00:07:00'),(10,107,'00:07:00'),(6,79,'00:08:00'),(12,129,'00:08:00'),(5,59,'00:09:00'),(11,122,'00:09:00'),(9,106,'00:10:00'),(10,106,'00:10:00'),(6,78,'00:11:00'),(12,128,'00:11:00'),(5,58,'00:12:00'),(11,121,'00:12:00'),(6,77,'00:13:00'),(9,105,'00:13:00'),(10,105,'00:13:00'),(5,57,'00:14:00'),(12,127,'00:14:00'),(6,76,'00:15:00'),(11,120,'00:16:00'),(5,31,'00:17:00'),(6,75,'00:18:00'),(9,104,'00:18:00'),(10,104,'00:18:00'),(5,63,'00:19:00'),(11,119,'00:19:00'),(9,103,'00:20:00'),(10,103,'00:20:00'),(12,126,'00:20:00'),(5,64,'00:21:00'),(6,74,'00:21:00'),(9,102,'00:22:00'),(10,102,'00:22:00'),(11,118,'00:23:00'),(5,65,'00:24:00'),(6,73,'00:24:00'),(12,122,'00:24:00'),(11,117,'00:26:00'),(5,66,'00:27:00'),(6,72,'00:27:00'),(9,101,'00:27:00'),(10,101,'00:27:00'),(12,121,'00:27:00'),(11,116,'00:28:00'),(5,3,'00:30:00'),(6,71,'00:30:00'),(9,100,'00:30:00'),(10,100,'00:30:00'),(11,115,'00:30:00'),(12,120,'00:31:00'),(6,70,'00:32:00'),(9,99,'00:32:00'),(10,99,'00:32:00'),(5,67,'00:33:00'),(11,114,'00:33:00'),(6,69,'00:34:00'),(9,98,'00:34:00'),(10,98,'00:34:00'),(12,119,'00:34:00'),(5,68,'00:35:00'),(11,113,'00:35:00'),(6,68,'00:37:00'),(9,97,'00:37:00'),(10,97,'00:37:00'),(11,112,'00:37:00'),(5,69,'00:38:00'),(12,118,'00:38:00'),(6,67,'00:39:00'),(11,64,'00:39:00'),(5,70,'00:40:00'),(9,19,'00:40:00'),(10,19,'00:40:00'),(11,11,'00:41:00'),(12,117,'00:41:00'),(5,71,'00:42:00'),(6,3,'00:42:00'),(9,110,'00:42:00'),(10,110,'00:42:00'),(12,116,'00:43:00'),(11,30,'00:44:00'),(5,72,'00:45:00'),(6,66,'00:45:00'),(12,115,'00:45:00'),(9,30,'00:46:00'),(10,30,'00:46:00'),(5,73,'00:48:00'),(6,65,'00:48:00'),(11,110,'00:48:00'),(12,114,'00:48:00'),(9,11,'00:49:00'),(10,11,'00:49:00'),(11,19,'00:50:00'),(12,113,'00:50:00'),(5,74,'00:51:00'),(6,64,'00:51:00'),(9,64,'00:51:00'),(10,64,'00:51:00'),(12,112,'00:52:00'),(6,63,'00:53:00'),(9,112,'00:53:00'),(10,112,'00:53:00'),(11,97,'00:53:00'),(5,75,'00:54:00'),(12,64,'00:54:00'),(6,31,'00:55:00'),(9,113,'00:55:00'),(10,113,'00:55:00'),(11,98,'00:56:00'),(12,11,'00:56:00'),(5,76,'00:57:00'),(9,114,'00:57:00'),(10,114,'00:57:00'),(6,57,'00:58:00'),(11,99,'00:58:00'),(5,77,'00:59:00'),(12,30,'00:59:00'),(6,58,'01:00:00'),(9,115,'01:00:00'),(10,115,'01:00:00'),(11,100,'01:00:00'),(5,78,'01:01:00'),(9,116,'01:02:00'),(10,116,'01:02:00'),(6,59,'01:03:00'),(11,101,'01:03:00'),(12,110,'01:03:00'),(5,79,'01:04:00'),(9,117,'01:04:00'),(10,117,'01:04:00'),(6,60,'01:05:00'),(12,19,'01:05:00'),(5,80,'01:06:00'),(9,118,'01:07:00'),(10,118,'01:07:00'),(6,61,'01:08:00'),(11,102,'01:08:00'),(12,97,'01:08:00'),(5,81,'01:09:00'),(6,62,'01:10:00'),(11,103,'01:10:00'),(9,119,'01:11:00'),(10,119,'01:11:00'),(12,98,'01:11:00'),(5,82,'01:12:00'),(6,23,'01:12:00'),(11,104,'01:12:00'),(12,99,'01:13:00'),(9,120,'01:14:00'),(10,120,'01:14:00'),(12,100,'01:15:00'),(11,105,'01:17:00'),(9,121,'01:18:00'),(10,121,'01:18:00'),(12,101,'01:18:00'),(11,106,'01:20:00'),(9,122,'01:21:00'),(10,122,'01:21:00'),(11,107,'01:23:00'),(12,102,'01:23:00'),(9,123,'01:24:00'),(10,126,'01:25:00'),(12,103,'01:25:00'),(11,108,'01:26:00'),(12,104,'01:27:00'),(9,124,'01:28:00'),(9,125,'01:30:00'),(11,109,'01:30:00'),(10,127,'01:31:00'),(12,105,'01:32:00'),(10,128,'01:34:00'),(12,106,'01:35:00'),(10,129,'01:37:00'),(12,107,'01:38:00'),(10,130,'01:39:00'),(12,108,'01:41:00'),(10,131,'01:43:00'),(10,132,'01:45:00'),(12,109,'01:45:00');
/*!40000 ALTER TABLE `costtime` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `deal`
--

DROP TABLE IF EXISTS `deal`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `deal` (
  `Dno` int NOT NULL AUTO_INCREMENT,
  `DUid` varchar(20) DEFAULT NULL,
  `Dstart` int DEFAULT NULL,
  `Dend` int DEFAULT NULL,
  `Din_time` datetime DEFAULT NULL,
  `Dout_time` datetime DEFAULT NULL,
  `Dcost` decimal(4,2) DEFAULT NULL,
  `Dtransfer` int DEFAULT NULL,
  PRIMARY KEY (`Dno`),
  KEY `Deal_uid_index` (`DUid`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `deal`
--

LOCK TABLES `deal` WRITE;
/*!40000 ALTER TABLE `deal` DISABLE KEYS */;
INSERT INTO `deal` VALUES (7,'18278409587',41,128,'1777-07-21 20:51:32','1777-07-21 20:51:32',4.00,0),(8,'uid',1,NULL,'2024-11-14 15:32:47',NULL,NULL,NULL),(9,'18278409587',127,64,'1778-11-21 08:26:58','1778-11-21 08:26:58',5.00,1),(10,'18278409587',64,46,'1778-11-21 08:46:58','1778-11-21 08:46:58',2.00,0),(11,'18278409587',3,3,'1778-11-21 09:46:58','1778-11-21 09:47:58',3.00,1),(12,'18278409587',3,128,'1778-11-21 09:48:58','1778-11-21 10:48:58',6.00,0),(13,'18278409587',3,3,'1779-11-21 10:37:07','1779-11-21 10:38:07',3.00,1),(14,'18278409587',3,128,'1779-11-21 10:39:07','1779-11-21 11:55:09',3.00,0),(15,'18278409587',23,128,'1779-12-21 11:55:10','1779-12-21 13:55:10',7.00,0),(16,'18278409587',132,56,'1779-12-22 13:55:10','1779-12-22 16:55:10',7.00,0),(17,'18278409587',128,23,'1780-11-24 19:58:31','1780-11-24 20:59:31',7.00,0),(18,'18278409587',3,3,'1780-11-24 20:59:31','1780-11-24 21:59:31',3.00,1),(19,'18278409587',3,128,'1780-11-24 21:59:31','1780-11-24 22:59:31',3.00,0);
/*!40000 ALTER TABLE `deal` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `edge`
--

DROP TABLE IF EXISTS `edge`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `edge` (
  `Eno` int NOT NULL,
  `Estart` int DEFAULT NULL,
  `Eend` int DEFAULT NULL,
  `Elength` double DEFAULT NULL,
  `Etype` int DEFAULT NULL,
  PRIMARY KEY (`Eno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `edge`
--

LOCK TABLES `edge` WRITE;
/*!40000 ALTER TABLE `edge` DISABLE KEYS */;
INSERT INTO `edge` VALUES (0,2,1,1,0),(1,1,2,1,0),(2,0,2,1,0),(3,2,0,1,0),(4,1,3,1,0),(5,3,1,1,0),(6,4,3,2,0),(7,3,4,2,0),(8,5,4,2,0),(9,4,5,2,0),(10,5,6,3,0),(11,6,5,3,0),(12,7,6,3,0),(13,6,7,3,0),(14,7,8,3,0),(15,8,7,3,0),(16,9,8,3,0),(17,8,9,3,0),(18,9,10,3,0),(19,10,9,3,0),(20,11,10,3,0),(21,10,11,3,0),(22,11,12,3,0),(23,12,11,3,0),(24,13,12,3,0),(25,12,13,3,0),(26,14,13,3,0),(27,13,14,3,0),(28,14,15,3,0),(29,15,14,3,0),(30,16,0,1,0),(31,0,16,1,0),(32,17,16,1,1),(33,16,17,1,2),(34,18,17,1,0),(35,17,18,1,0),(36,18,20,1,0),(37,20,18,1,0),(38,19,20,1,0),(39,20,19,1,0),(40,19,21,1,0),(41,21,19,1,0),(42,22,21,2,2),(43,21,22,2,1),(44,22,23,2,0),(45,23,22,2,0),(46,23,24,2,0),(47,24,23,2,0),(48,24,25,3,0),(49,25,24,3,0),(50,25,26,3,0),(51,26,25,3,0),(52,26,27,3,0),(53,27,26,3,0),(54,28,0,1,0),(55,0,28,1,0),(56,28,29,1,0),(57,29,28,1,0),(58,30,29,1,0),(59,29,30,1,0),(60,30,31,2,0),(61,31,30,2,0),(62,32,31,3,0),(63,31,32,3,0),(64,33,32,3,0),(65,32,33,3,0),(66,33,34,3,0),(67,34,33,3,0),(68,35,34,3,0),(69,34,35,3,0),(70,35,36,3,0),(71,36,35,3,0),(72,37,36,3,0),(73,36,37,3,0),(74,37,38,3,0),(75,38,37,3,0),(76,39,0,1,0),(77,0,39,1,0),(78,39,40,1,0),(79,40,39,1,0),(80,41,40,1,0),(81,40,41,1,0),(82,41,42,2,0),(83,42,41,2,0),(84,43,42,2,0),(85,42,43,2,0),(86,43,44,2,0),(87,44,43,2,0),(88,45,44,3,0),(89,44,45,3,0),(90,45,46,3,0),(91,46,45,3,0),(92,47,46,3,0),(93,46,47,3,0),(94,47,48,3,0),(95,48,47,3,0),(96,49,48,3,0),(97,48,49,3,0),(98,49,50,3,0),(99,50,49,3,0),(100,50,51,3,1),(101,51,50,3,2),(102,52,51,3,0),(103,51,52,3,0),(104,52,53,3,0),(105,53,52,3,0),(106,54,53,3,0),(107,53,54,3,0),(108,54,55,3,0),(109,55,54,3,0),(110,56,55,6,0),(111,55,56,6,0),(112,57,31,1,0),(113,31,57,1,0),(114,57,58,1,0),(115,58,57,1,0),(116,59,58,1,0),(117,58,59,1,0),(118,59,60,1,2),(119,60,59,1,1),(120,61,60,1,0),(121,60,61,1,0),(122,61,62,1,2),(123,62,61,1,1),(124,23,62,1,0),(125,62,23,1,0),(126,63,31,1,0),(127,31,63,1,0),(128,64,63,1,1),(129,63,64,1,2),(130,64,65,1,0),(131,65,64,1,0),(132,66,65,1,0),(133,65,66,1,0),(134,66,3,1,0),(135,3,66,1,0),(136,67,3,1,0),(137,3,67,1,0),(138,67,68,1,0),(139,68,67,1,0),(140,68,69,2,0),(141,69,68,2,0),(142,70,69,2,0),(143,69,70,2,0),(144,70,71,2,0),(145,71,70,2,0),(146,72,71,2,0),(147,71,72,2,0),(148,72,73,2,0),(149,73,72,2,0),(150,74,73,3,0),(151,73,74,3,0),(152,74,75,3,0),(153,75,74,3,0),(154,76,75,3,0),(155,75,76,3,0),(156,77,76,3,0),(157,76,77,3,0),(158,78,77,3,0),(159,77,78,3,0),(160,78,79,3,0),(161,79,78,3,0),(162,80,79,3,0),(163,79,80,3,0),(164,80,81,3,2),(165,81,80,3,1),(166,81,82,3,0),(167,82,81,3,0),(168,21,84,1,0),(169,84,21,1,0),(170,95,67,1,0),(171,67,95,1,0),(172,95,96,1,0),(173,96,95,1,0),(174,94,96,1,0),(175,96,94,1,0),(176,94,93,1,1),(177,93,94,1,2),(178,93,92,1,0),(179,92,93,1,0),(180,42,92,1,0),(181,92,42,1,0),(182,42,91,1,0),(183,91,42,1,0),(184,90,91,1,1),(185,91,90,1,2),(186,90,89,1,0),(187,89,90,1,0),(188,88,89,1,0),(189,89,88,1,0),(190,88,87,1,0),(191,87,88,1,0),(192,86,87,1,0),(193,87,86,1,0),(194,86,85,1,0),(195,85,86,1,0),(196,83,85,1,0),(197,85,83,1,0),(198,83,84,1,0),(199,84,83,1,0),(200,59,21,1,0),(201,21,59,1,0),(202,19,97,2,0),(203,97,19,2,0),(204,98,97,1,0),(205,97,98,1,0),(206,98,99,3,0),(207,99,98,3,0),(208,99,100,3,0),(209,100,99,3,0),(210,101,100,3,0),(211,100,101,3,0),(212,101,102,3,0),(213,102,101,3,0),(214,103,102,3,0),(215,102,103,3,0),(216,103,104,3,0),(217,104,103,3,0),(218,105,104,1,0),(219,104,105,1,0),(220,105,106,3,0),(221,106,105,3,0),(222,107,106,2,0),(223,106,107,1,0),(224,107,108,2,0),(225,108,107,1,0),(226,109,108,2,0),(227,108,109,2,0),(228,19,110,2,0),(229,110,19,2,0),(230,110,30,2,0),(231,30,110,2,0),(232,30,111,2,0),(233,111,30,2,0),(234,111,64,2,0),(235,64,111,2,0),(236,64,112,3,0),(237,112,64,3,0),(238,113,112,3,0),(239,112,113,3,0),(240,113,114,3,0),(241,114,113,3,0),(242,115,114,3,0),(243,114,115,3,0),(244,115,116,3,0),(245,116,115,3,0),(246,117,116,3,0),(247,116,117,3,0),(248,117,118,3,0),(249,118,117,3,0),(250,119,118,3,0),(251,118,119,3,0),(252,119,120,3,0),(253,120,119,3,0),(254,121,120,3,0),(255,120,121,3,0),(256,121,122,3,0),(257,122,121,3,0),(258,123,122,3,0),(259,122,123,3,0),(260,123,124,3,0),(261,124,123,3,0),(262,126,122,3,0),(263,122,126,3,0),(264,126,127,3,0),(265,127,126,3,0),(266,128,127,3,0),(267,127,128,3,0),(268,128,129,3,0),(269,129,128,3,0),(270,130,129,3,0),(271,129,130,3,0),(272,130,131,3,0),(273,131,130,3,0),(274,132,131,3,0),(275,131,132,3,0),(276,124,125,3,0),(277,125,124,3,0);
/*!40000 ALTER TABLE `edge` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `line`
--

DROP TABLE IF EXISTS `line`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `line` (
  `Lno` int NOT NULL,
  `Lname` varchar(50) DEFAULT NULL,
  `Lcolor` varchar(10) DEFAULT NULL,
  `Lcircle` int DEFAULT NULL,
  PRIMARY KEY (`Lno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `line`
--

LOCK TABLES `line` WRITE;
/*!40000 ALTER TABLE `line` DISABLE KEYS */;
INSERT INTO `line` VALUES (1,'1号线富锦路方向','ffe30043',0),(2,'1号线莘庄方向','ffe30043',0),(3,'2号线浦东国际机场方向','ff8cc232',0),(4,'2号线徐泾东方向','ff8cc232',0),(5,'3号线上海南站方向','fffcd600',0),(6,'3号线江杨北路方向','fffcd600',0),(7,'4号线内圈','ff702984',1),(8,'4号线外圈','ff702984',1),(9,'11号线嘉定北方向','ff872843',0),(10,'11号线花桥方向','ff872843',0),(11,'11号线迪士尼方向(嘉定北)','ff872843',0),(12,'11号线迪士尼方向(花桥)','ff872843',0);
/*!40000 ALTER TABLE `line` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `plan`
--

DROP TABLE IF EXISTS `plan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `plan` (
  `Pno` int NOT NULL AUTO_INCREMENT,
  `Pline` int DEFAULT NULL,
  `Ptrain` int DEFAULT NULL,
  `Ptime` time DEFAULT NULL,
  PRIMARY KEY (`Pno`),
  KEY `Plan_time_index` (`Ptime`)
) ENGINE=InnoDB AUTO_INCREMENT=597 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `plan`
--

LOCK TABLES `plan` WRITE;
/*!40000 ALTER TABLE `plan` DISABLE KEYS */;
INSERT INTO `plan` VALUES (5,9,27,'05:58:00'),(6,9,28,'06:10:00'),(7,9,29,'06:22:00'),(8,9,30,'06:34:00'),(9,9,31,'06:46:00'),(10,9,32,'06:58:00'),(11,9,33,'07:10:00'),(12,9,34,'07:22:00'),(13,9,35,'07:34:00'),(14,9,36,'07:46:00'),(15,9,37,'07:58:00'),(16,9,38,'08:10:00'),(17,9,39,'08:22:00'),(18,9,40,'08:34:00'),(19,9,41,'08:46:00'),(20,9,42,'08:58:00'),(21,9,27,'09:10:00'),(22,9,28,'09:22:00'),(23,9,29,'09:34:00'),(24,9,30,'09:46:00'),(25,9,31,'09:58:00'),(26,9,32,'10:10:00'),(27,9,33,'10:22:00'),(28,9,34,'10:34:00'),(29,9,35,'10:46:00'),(30,9,36,'10:58:00'),(31,9,37,'11:10:00'),(32,9,38,'11:22:00'),(33,9,39,'11:34:00'),(34,9,40,'11:46:00'),(35,9,41,'11:58:00'),(36,9,42,'12:10:00'),(37,9,27,'12:22:00'),(38,9,28,'12:34:00'),(39,9,29,'12:46:00'),(40,9,30,'12:58:00'),(41,9,31,'13:10:00'),(42,9,32,'13:22:00'),(43,9,33,'13:34:00'),(44,9,34,'13:46:00'),(45,9,35,'13:58:00'),(46,9,36,'14:10:00'),(47,9,37,'14:22:00'),(48,9,38,'14:34:00'),(49,9,39,'14:46:00'),(50,9,40,'14:58:00'),(51,9,41,'15:10:00'),(52,9,42,'15:22:00'),(53,9,27,'15:34:00'),(54,9,28,'15:46:00'),(55,9,29,'15:58:00'),(56,9,30,'16:10:00'),(57,9,31,'16:22:00'),(58,9,32,'16:34:00'),(59,9,33,'16:46:00'),(60,9,34,'16:58:00'),(61,9,35,'17:10:00'),(62,9,36,'17:22:00'),(63,9,37,'17:34:00'),(64,9,38,'17:46:00'),(65,9,39,'17:58:00'),(66,9,40,'18:10:00'),(67,9,41,'18:22:00'),(68,9,42,'18:34:00'),(69,9,27,'18:46:00'),(70,9,28,'18:58:00'),(71,9,29,'19:10:00'),(72,9,30,'19:22:00'),(73,9,31,'19:34:00'),(74,9,32,'19:46:00'),(75,9,33,'19:58:00'),(76,9,34,'20:10:00'),(77,9,35,'20:22:00'),(78,9,36,'20:34:00'),(79,9,37,'20:46:00'),(80,9,38,'20:58:00'),(81,9,39,'21:10:00'),(82,9,40,'21:22:00'),(83,9,41,'21:34:00'),(84,9,42,'21:46:00'),(85,9,27,'21:58:00'),(86,9,28,'22:10:00'),(87,9,29,'22:22:00'),(88,11,35,'05:36:00'),(89,11,36,'05:48:00'),(90,11,37,'06:00:00'),(91,11,38,'06:12:00'),(92,11,39,'06:24:00'),(93,11,40,'06:36:00'),(94,11,41,'06:48:00'),(95,11,42,'07:00:00'),(96,11,27,'07:12:00'),(97,11,28,'07:24:00'),(98,11,29,'07:36:00'),(99,11,30,'07:48:00'),(100,11,31,'08:00:00'),(101,11,32,'08:12:00'),(102,11,33,'08:24:00'),(103,11,34,'08:36:00'),(104,11,35,'08:48:00'),(105,11,36,'09:00:00'),(106,11,37,'09:12:00'),(107,11,38,'09:24:00'),(108,11,39,'09:36:00'),(109,11,40,'09:48:00'),(110,11,41,'10:00:00'),(111,11,42,'10:12:00'),(112,11,27,'10:24:00'),(113,11,28,'10:36:00'),(114,11,29,'10:48:00'),(115,11,30,'11:00:00'),(116,11,31,'11:12:00'),(117,11,32,'11:24:00'),(118,11,33,'11:36:00'),(119,11,34,'11:48:00'),(120,11,35,'12:00:00'),(121,11,36,'12:12:00'),(122,11,37,'12:24:00'),(123,11,38,'12:36:00'),(124,11,39,'12:48:00'),(125,11,40,'13:00:00'),(126,11,41,'13:12:00'),(127,11,42,'13:24:00'),(128,11,27,'13:36:00'),(129,11,28,'13:48:00'),(130,11,29,'14:00:00'),(131,11,30,'14:12:00'),(132,11,31,'14:24:00'),(133,11,32,'14:36:00'),(134,11,33,'14:48:00'),(135,11,34,'15:00:00'),(136,11,35,'15:12:00'),(137,11,36,'15:24:00'),(138,11,37,'15:36:00'),(139,11,38,'15:48:00'),(140,11,39,'16:00:00'),(141,11,40,'16:12:00'),(142,11,41,'16:24:00'),(143,11,42,'16:36:00'),(144,11,27,'16:48:00'),(145,11,28,'17:00:00'),(146,11,29,'17:12:00'),(147,11,30,'17:24:00'),(148,11,31,'17:36:00'),(149,11,32,'17:48:00'),(150,11,33,'18:00:00'),(151,11,34,'18:12:00'),(152,11,35,'18:24:00'),(153,11,36,'18:36:00'),(154,11,37,'18:48:00'),(155,11,38,'19:00:00'),(156,11,39,'19:12:00'),(157,11,40,'19:24:00'),(158,11,41,'19:36:00'),(159,11,42,'19:48:00'),(160,11,27,'20:00:00'),(161,11,28,'20:12:00'),(162,11,29,'20:24:00'),(163,11,30,'20:36:00'),(164,11,31,'20:48:00'),(165,11,32,'21:00:00'),(166,11,33,'21:12:00'),(167,11,34,'21:24:00'),(168,11,35,'21:36:00'),(169,11,36,'21:48:00'),(170,11,37,'22:00:00'),(171,10,43,'05:25:00'),(172,10,44,'05:37:00'),(173,10,45,'05:49:00'),(174,10,46,'06:01:00'),(175,10,47,'06:13:00'),(176,10,48,'06:25:00'),(177,10,49,'06:37:00'),(178,10,50,'06:49:00'),(179,10,51,'07:01:00'),(180,10,52,'07:13:00'),(181,10,53,'07:25:00'),(182,10,54,'07:37:00'),(183,10,55,'07:49:00'),(184,10,56,'08:01:00'),(185,10,57,'08:13:00'),(186,10,58,'08:25:00'),(187,10,59,'08:37:00'),(188,10,60,'08:49:00'),(189,10,43,'09:01:00'),(190,10,44,'09:13:00'),(191,10,45,'09:25:00'),(192,10,46,'09:37:00'),(193,10,47,'09:49:00'),(194,10,48,'10:01:00'),(195,10,49,'10:13:00'),(196,10,50,'10:25:00'),(197,10,51,'10:37:00'),(198,10,52,'10:49:00'),(199,10,53,'11:01:00'),(200,10,54,'11:13:00'),(201,10,55,'11:25:00'),(202,10,56,'11:37:00'),(203,10,57,'11:49:00'),(204,10,58,'12:01:00'),(205,10,59,'12:13:00'),(206,10,60,'12:25:00'),(207,10,43,'12:37:00'),(208,10,44,'12:49:00'),(209,10,45,'13:01:00'),(210,10,46,'13:13:00'),(211,10,47,'13:25:00'),(212,10,48,'13:37:00'),(213,10,49,'13:49:00'),(214,10,50,'14:01:00'),(215,10,51,'14:13:00'),(216,10,52,'14:25:00'),(217,10,53,'14:37:00'),(218,10,54,'14:49:00'),(219,10,55,'15:01:00'),(220,10,56,'15:13:00'),(221,10,57,'15:25:00'),(222,10,58,'15:37:00'),(223,10,59,'15:49:00'),(224,10,60,'16:01:00'),(225,10,43,'16:13:00'),(226,10,44,'16:25:00'),(227,10,45,'16:37:00'),(228,10,46,'16:49:00'),(229,10,47,'17:01:00'),(230,10,48,'17:13:00'),(231,10,49,'17:25:00'),(232,10,50,'17:37:00'),(233,10,51,'17:49:00'),(234,10,52,'18:01:00'),(235,10,53,'18:13:00'),(236,10,54,'18:25:00'),(237,10,55,'18:37:00'),(238,10,56,'18:49:00'),(239,10,57,'19:01:00'),(240,10,58,'19:13:00'),(241,10,59,'19:25:00'),(242,10,60,'19:37:00'),(243,10,43,'19:49:00'),(244,10,44,'20:01:00'),(245,10,45,'20:13:00'),(246,10,46,'20:25:00'),(247,10,47,'20:37:00'),(248,10,48,'20:49:00'),(249,10,49,'21:01:00'),(250,10,50,'21:13:00'),(251,10,51,'21:25:00'),(252,10,52,'21:37:00'),(253,10,53,'21:49:00'),(254,12,52,'05:37:00'),(255,12,53,'05:49:00'),(256,12,54,'06:01:00'),(257,12,55,'06:13:00'),(258,12,56,'06:25:00'),(259,12,57,'06:37:00'),(260,12,58,'06:49:00'),(261,12,59,'07:01:00'),(262,12,60,'07:13:00'),(263,12,43,'07:25:00'),(264,12,44,'07:37:00'),(265,12,45,'07:49:00'),(266,12,46,'08:01:00'),(267,12,47,'08:13:00'),(268,12,48,'08:25:00'),(269,12,49,'08:37:00'),(270,12,50,'08:49:00'),(271,12,51,'09:01:00'),(272,12,52,'09:13:00'),(273,12,53,'09:25:00'),(274,12,54,'09:37:00'),(275,12,55,'09:49:00'),(276,12,56,'10:01:00'),(277,12,57,'10:13:00'),(278,12,58,'10:25:00'),(279,12,59,'10:37:00'),(280,12,60,'10:49:00'),(281,12,43,'11:01:00'),(282,12,44,'11:13:00'),(283,12,45,'11:25:00'),(284,12,46,'11:37:00'),(285,12,47,'11:49:00'),(286,12,48,'12:01:00'),(287,12,49,'12:13:00'),(288,12,50,'12:25:00'),(289,12,51,'12:37:00'),(290,12,52,'12:49:00'),(291,12,53,'13:01:00'),(292,12,54,'13:13:00'),(293,12,55,'13:25:00'),(294,12,56,'13:37:00'),(295,12,57,'13:49:00'),(296,12,58,'14:01:00'),(297,12,59,'14:13:00'),(298,12,60,'14:25:00'),(299,12,43,'14:37:00'),(300,12,44,'14:49:00'),(301,12,45,'15:01:00'),(302,12,46,'15:13:00'),(303,12,47,'15:25:00'),(304,12,48,'15:37:00'),(305,12,49,'15:49:00'),(306,12,50,'16:01:00'),(307,12,51,'16:13:00'),(308,12,52,'16:25:00'),(309,12,53,'16:37:00'),(310,12,54,'16:49:00'),(311,12,55,'17:01:00'),(312,12,56,'17:13:00'),(313,12,57,'17:25:00'),(314,12,58,'17:37:00'),(315,12,59,'17:49:00'),(316,12,60,'18:01:00'),(317,12,43,'18:13:00'),(318,12,44,'18:25:00'),(319,12,45,'18:37:00'),(320,12,46,'18:49:00'),(321,12,47,'19:01:00'),(322,12,48,'19:13:00'),(323,12,49,'19:25:00'),(324,12,50,'19:37:00'),(325,12,51,'19:49:00'),(326,12,52,'20:01:00'),(327,12,53,'20:13:00'),(328,12,54,'20:25:00'),(329,12,55,'20:37:00'),(330,12,56,'20:49:00'),(331,12,57,'21:01:00'),(332,12,58,'21:13:00'),(333,12,59,'21:25:00'),(334,12,60,'21:37:00'),(335,12,43,'21:49:00'),(336,5,61,'05:20:00'),(337,5,62,'05:28:00'),(338,5,63,'05:36:00'),(339,5,64,'05:44:00'),(340,5,65,'05:52:00'),(341,5,66,'06:00:00'),(342,5,67,'06:08:00'),(343,5,68,'06:16:00'),(344,5,69,'06:24:00'),(345,5,70,'06:32:00'),(346,5,71,'06:40:00'),(347,5,72,'06:48:00'),(348,5,73,'06:56:00'),(349,5,74,'07:04:00'),(350,5,75,'07:12:00'),(351,5,76,'07:20:00'),(352,5,77,'07:28:00'),(353,5,78,'07:36:00'),(354,5,61,'07:44:00'),(355,5,62,'07:52:00'),(356,5,63,'08:00:00'),(357,5,64,'08:08:00'),(358,5,65,'08:16:00'),(359,5,66,'08:24:00'),(360,5,67,'08:32:00'),(361,5,68,'08:40:00'),(362,5,69,'08:48:00'),(363,5,70,'08:56:00'),(364,5,71,'09:04:00'),(365,5,72,'09:12:00'),(366,5,73,'09:20:00'),(367,5,74,'09:28:00'),(368,5,75,'09:36:00'),(369,5,76,'09:44:00'),(370,5,77,'09:52:00'),(371,5,78,'10:00:00'),(372,5,61,'10:08:00'),(373,5,62,'10:16:00'),(374,5,63,'10:24:00'),(375,5,64,'10:32:00'),(376,5,65,'10:40:00'),(377,5,66,'10:48:00'),(378,5,67,'10:56:00'),(379,5,68,'11:04:00'),(380,5,69,'11:12:00'),(381,5,70,'11:20:00'),(382,5,71,'11:28:00'),(383,5,72,'11:36:00'),(384,5,73,'11:44:00'),(385,5,74,'11:52:00'),(386,5,75,'12:00:00'),(387,5,76,'12:08:00'),(388,5,77,'12:16:00'),(389,5,78,'12:24:00'),(390,5,61,'12:32:00'),(391,5,62,'12:40:00'),(392,5,63,'12:48:00'),(393,5,64,'12:56:00'),(394,5,65,'13:04:00'),(395,5,66,'13:12:00'),(396,5,67,'13:20:00'),(397,5,68,'13:28:00'),(398,5,69,'13:36:00'),(399,5,70,'13:44:00'),(400,5,71,'13:52:00'),(401,5,72,'14:00:00'),(402,5,73,'14:08:00'),(403,5,74,'14:16:00'),(404,5,75,'14:24:00'),(405,5,76,'14:32:00'),(406,5,77,'14:40:00'),(407,5,78,'14:48:00'),(408,5,61,'14:56:00'),(409,5,62,'15:04:00'),(410,5,63,'15:12:00'),(411,5,64,'15:20:00'),(412,5,65,'15:28:00'),(413,5,66,'15:36:00'),(414,5,67,'15:44:00'),(415,5,68,'15:52:00'),(416,5,69,'16:00:00'),(417,5,70,'16:08:00'),(418,5,71,'16:16:00'),(419,5,72,'16:24:00'),(420,5,73,'16:32:00'),(421,5,74,'16:40:00'),(422,5,75,'16:48:00'),(423,5,76,'16:56:00'),(424,5,77,'17:04:00'),(425,5,78,'17:12:00'),(426,5,61,'17:20:00'),(427,5,62,'17:28:00'),(428,5,63,'17:36:00'),(429,5,64,'17:44:00'),(430,5,65,'17:52:00'),(431,5,66,'18:00:00'),(432,5,67,'18:08:00'),(433,5,68,'18:16:00'),(434,5,69,'18:24:00'),(435,5,70,'18:32:00'),(436,5,71,'18:40:00'),(437,5,72,'18:48:00'),(438,5,73,'18:56:00'),(439,5,74,'19:04:00'),(440,5,75,'19:12:00'),(441,5,76,'19:20:00'),(442,5,77,'19:28:00'),(443,5,78,'19:36:00'),(444,5,61,'19:44:00'),(445,5,62,'19:52:00'),(446,5,63,'20:00:00'),(447,5,64,'20:08:00'),(448,5,65,'20:16:00'),(449,5,66,'20:24:00'),(450,5,67,'20:32:00'),(451,5,68,'20:40:00'),(452,5,69,'20:48:00'),(453,5,70,'20:56:00'),(454,5,71,'21:04:00'),(455,5,72,'21:12:00'),(456,5,73,'21:20:00'),(457,5,74,'21:28:00'),(458,5,75,'21:36:00'),(459,5,76,'21:44:00'),(460,5,77,'21:52:00'),(461,5,78,'22:00:00'),(462,5,61,'22:08:00'),(463,5,62,'22:16:00'),(464,5,63,'22:24:00'),(465,5,64,'22:32:00'),(466,5,65,'22:40:00'),(467,6,61,'05:20:00'),(468,6,62,'05:28:00'),(469,6,63,'05:36:00'),(470,6,64,'05:44:00'),(471,6,65,'05:52:00'),(472,6,66,'06:00:00'),(473,6,67,'06:08:00'),(474,6,68,'06:16:00'),(475,6,69,'06:24:00'),(476,6,70,'06:32:00'),(477,6,71,'06:40:00'),(478,6,72,'06:48:00'),(479,6,73,'06:56:00'),(480,6,74,'07:04:00'),(481,6,75,'07:12:00'),(482,6,76,'07:20:00'),(483,6,77,'07:28:00'),(484,6,78,'07:36:00'),(485,6,61,'07:44:00'),(486,6,62,'07:52:00'),(487,6,63,'08:00:00'),(488,6,64,'08:08:00'),(489,6,65,'08:16:00'),(490,6,66,'08:24:00'),(491,6,67,'08:32:00'),(492,6,68,'08:40:00'),(493,6,69,'08:48:00'),(494,6,70,'08:56:00'),(495,6,71,'09:04:00'),(496,6,72,'09:12:00'),(497,6,73,'09:20:00'),(498,6,74,'09:28:00'),(499,6,75,'09:36:00'),(500,6,76,'09:44:00'),(501,6,77,'09:52:00'),(502,6,78,'10:00:00'),(503,6,61,'10:08:00'),(504,6,62,'10:16:00'),(505,6,63,'10:24:00'),(506,6,64,'10:32:00'),(507,6,65,'10:40:00'),(508,6,66,'10:48:00'),(509,6,67,'10:56:00'),(510,6,68,'11:04:00'),(511,6,69,'11:12:00'),(512,6,70,'11:20:00'),(513,6,71,'11:28:00'),(514,6,72,'11:36:00'),(515,6,73,'11:44:00'),(516,6,74,'11:52:00'),(517,6,75,'12:00:00'),(518,6,76,'12:08:00'),(519,6,77,'12:16:00'),(520,6,78,'12:24:00'),(521,6,61,'12:32:00'),(522,6,62,'12:40:00'),(523,6,63,'12:48:00'),(524,6,64,'12:56:00'),(525,6,65,'13:04:00'),(526,6,66,'13:12:00'),(527,6,67,'13:20:00'),(528,6,68,'13:28:00'),(529,6,69,'13:36:00'),(530,6,70,'13:44:00'),(531,6,71,'13:52:00'),(532,6,72,'14:00:00'),(533,6,73,'14:08:00'),(534,6,74,'14:16:00'),(535,6,75,'14:24:00'),(536,6,76,'14:32:00'),(537,6,77,'14:40:00'),(538,6,78,'14:48:00'),(539,6,61,'14:56:00'),(540,6,62,'15:04:00'),(541,6,63,'15:12:00'),(542,6,64,'15:20:00'),(543,6,65,'15:28:00'),(544,6,66,'15:36:00'),(545,6,67,'15:44:00'),(546,6,68,'15:52:00'),(547,6,69,'16:00:00'),(548,6,70,'16:08:00'),(549,6,71,'16:16:00'),(550,6,72,'16:24:00'),(551,6,73,'16:32:00'),(552,6,74,'16:40:00'),(553,6,75,'16:48:00'),(554,6,76,'16:56:00'),(555,6,77,'17:04:00'),(556,6,78,'17:12:00'),(557,6,61,'17:20:00'),(558,6,62,'17:28:00'),(559,6,63,'17:36:00'),(560,6,64,'17:44:00'),(561,6,65,'17:52:00'),(562,6,66,'18:00:00'),(563,6,67,'18:08:00'),(564,6,68,'18:16:00'),(565,6,69,'18:24:00'),(566,6,70,'18:32:00'),(567,6,71,'18:40:00'),(568,6,72,'18:48:00'),(569,6,73,'18:56:00'),(570,6,74,'19:04:00'),(571,6,75,'19:12:00'),(572,6,76,'19:20:00'),(573,6,77,'19:28:00'),(574,6,78,'19:36:00'),(575,6,61,'19:44:00'),(576,6,62,'19:52:00'),(577,6,63,'20:00:00'),(578,6,64,'20:08:00'),(579,6,65,'20:16:00'),(580,6,66,'20:24:00'),(581,6,67,'20:32:00'),(582,6,68,'20:40:00'),(583,6,69,'20:48:00'),(584,6,70,'20:56:00'),(585,6,71,'21:04:00'),(586,6,72,'21:12:00'),(587,6,73,'21:20:00'),(588,6,74,'21:28:00'),(589,6,75,'21:36:00'),(590,6,76,'21:44:00'),(591,6,77,'21:52:00'),(592,6,78,'22:00:00'),(593,6,61,'22:08:00'),(594,6,62,'22:16:00'),(595,6,63,'22:24:00'),(596,6,64,'22:32:00');
/*!40000 ALTER TABLE `plan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `station`
--

DROP TABLE IF EXISTS `station`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `station` (
  `Sno` int NOT NULL,
  `Sname` varchar(20) DEFAULT NULL,
  `Stransfer` int DEFAULT NULL,
  `Sx` double DEFAULT NULL,
  `Sy` double DEFAULT NULL,
  PRIMARY KEY (`Sno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `station`
--

LOCK TABLES `station` WRITE;
/*!40000 ALTER TABLE `station` DISABLE KEYS */;
INSERT INTO `station` VALUES (0,'人民广场',0,46,20),(1,'汉中路',0,-57,-105),(2,'新闸路',0,-10,-45),(3,'上海火车站',1,-57,-204),(4,'中山北路',0,-57,-270),(5,'延长路',0,-57,-330),(6,'上海马戏城',0,-57,-390),(7,'汶水路',0,-57,-450),(8,'彭浦新村',0,-57,-510),(9,'共康路',0,-57,-570),(10,'通河新村',0,-57,-630),(11,'呼兰路',0,-57,-690),(12,'共富新村',0,-57,-750),(13,'宝安公路',0,-57,-810),(14,'友谊西路',0,-56,-861),(15,'富锦路',0,-57,-917),(16,'一大会址·黄陂南路',0,-7,87),(17,'陕西南路',0,-162,113),(18,'常熟路',0,-281,113),(19,'徐家汇',0,-407,240),(20,'衡山路',0,-372,206),(21,'上海体育馆',0,-473,309),(22,'漕宝路',0,-543,398),(23,'上海南站',0,-601,444),(24,'锦江乐园',0,-653,484),(25,'莲花路',0,-697,518),(26,'外环路',0,-749,560),(27,'莘庄',0,-801,602),(28,'南京西路',1,-79,20),(29,'静安寺',0,-281,20),(30,'江苏路',0,-407,20),(31,'中山公园',0,-495,20),(32,'娄山关路',1,-578,20),(33,'威宁路',0,-664,20),(34,'北新泾',0,-749,20),(35,'淞虹路',0,-831,20),(36,'虹桥2号航站楼',1,-903,49),(37,'虹桥火车站',0,-990,49),(38,'徐泾东',0,-1042,49),(39,'南京东路',0,178,20),(40,'陆家嘴',0,302,54),(41,'东昌路',0,337,82),(42,'世纪大道',0,418,157),(43,'上海科技馆',0,466,200),(44,'世纪公园',0,520,248),(45,'龙阳路',0,573,294),(46,'张江高科',0,687,294),(47,'金科路',0,761,294),(48,'广兰路',0,832,294),(49,'唐镇',0,907,294),(50,'创新中路',0,977,294),(51,'华夏东路',0,1031,340),(52,'川沙',0,1031,393),(53,'凌空路',0,1031,444),(54,'远东大道',0,1031,490),(55,'海天三路',0,1031,536),(56,'浦东国际机场',0,1031,871),(57,'延安西路',0,-494,75),(58,'虹桥路',0,-495,147),(59,'宜山路',0,-495,240),(60,'漕溪路',0,-474,353),(61,'龙漕路',0,-460,398),(62,'石龙路',0,-495,444),(63,'金沙江路',0,-495,-105),(64,'曹杨路',1,-407,-204),(65,'镇坪路',0,-281,-204),(66,'中潭路',0,-162,-204),(67,'宝山路',0,72,-204),(68,'东宝兴路',0,136,-253),(69,'虹口足球场',0,136,-288),(70,'赤峰路',0,136,-353),(71,'大柏树',0,136,-409),(72,'江湾镇',0,136,-450),(73,'殷高西路',0,136,-498),(74,'长江南路',0,178,-570),(75,'淞发路',0,254,-630),(76,'张华浜',0,330,-711),(77,'淞滨路',0,330,-755),(78,'水产路',0,330,-802),(79,'宝杨路',0,330,-847),(80,'友谊路',0,330,-891),(81,'铁力路',0,273,-917),(82,'江杨北路',0,210,-917),(83,'东安路',0,-281,330),(84,'上海体育场',0,-348,330),(85,'大木桥路',0,-162,330),(86,'鲁班路',0,-97,330),(87,'西藏南路',0,72,330),(88,'南浦大桥',0,178,330),(89,'塘桥',0,271,330),(90,'蓝村路',0,344,330),(91,'浦电路',0,418,248),(92,'浦东大道',0,418,20),(93,'杨树浦路',0,418,-94),(94,'大连路',0,390,-204),(95,'海伦路',0,176,-204),(96,'临平路',0,286,-204),(97,'上海游泳馆',0,-407,365),(98,'龙华',0,-407,396),(99,'云锦路',0,-304,482),(100,'龙耀路',0,-216,551),(101,'东方体育中心',0,-51,593),(102,'三林',0,72,647),(103,'三林东',0,247,647),(104,'浦三路',0,378,647),(105,'御桥',0,473,647),(106,'罗山路',0,643,647),(107,'秀沿路',0,726,647),(108,'康新公路',0,832,647),(109,'迪士尼',0,907,647),(110,'交通大学',0,-407,147),(111,'隆德路',0,-407,-105),(112,'枫桥路',0,-456,-256),(113,'真如',0,-504,-311),(114,'上海西站',0,-548,-363),(115,'李子园',0,-596,-416),(116,'祁连山路',0,-689,-461),(117,'武威路',0,-793,-507),(118,'桃浦新村',0,-834,-543),(119,'南翔',0,-869,-585),(120,'陈翔公路',0,-905,-627),(121,'马陆',0,-937,-667),(122,'嘉定新城',0,-971,-714),(123,'白银路',0,-1000,-779),(124,'嘉定西',0,-1000,-846),(125,'嘉定北',0,-1000,-917),(126,'上海赛车场',0,-1061,-714),(127,'昌吉东路',0,-1094,-682),(128,'上海汽车城',0,-1126,-650),(129,'安亭',0,-1160,-617),(130,'兆丰路',0,-1200,-585),(131,'光明路',0,-1259,-585),(132,'花桥',0,-1321,-585);
/*!40000 ALTER TABLE `station` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `train`
--

DROP TABLE IF EXISTS `train`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `train` (
  `Tno` int NOT NULL AUTO_INCREMENT,
  `Tmodel` varchar(20) DEFAULT NULL,
  `Ttemperature` int DEFAULT NULL,
  `Tcrowd` int DEFAULT NULL,
  PRIMARY KEY (`Tno`)
) ENGINE=InnoDB AUTO_INCREMENT=79 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `train`
--

LOCK TABLES `train` WRITE;
/*!40000 ALTER TABLE `train` DISABLE KEYS */;
INSERT INTO `train` VALUES (27,'AC-16',25,5),(28,'AC-16',25,5),(29,'AC-16',25,5),(30,'AC-16',25,5),(31,'AC-16',25,5),(32,'AC-16',25,5),(33,'AC-16',25,5),(34,'AC-16',25,5),(35,'AC-16',25,5),(36,'AC-16',25,5),(37,'AC-16',25,5),(38,'AC-16',25,5),(39,'AC-16',25,5),(40,'AC-16',25,5),(41,'AC-16',25,5),(42,'AC-16',25,5),(43,'AC-16',25,5),(44,'AC-16',25,5),(45,'AC-16',25,5),(46,'AC-16',25,5),(47,'11A02',25,5),(48,'11A02',25,5),(49,'11A02',25,5),(50,'11A02',25,5),(51,'11A02',25,5),(52,'11A02',25,5),(53,'11A03',25,5),(54,'11A03',25,5),(55,'11A03',25,5),(56,'11A03',25,5),(57,'11A03',25,5),(58,'11A03',25,5),(59,'03A02',25,5),(60,'03A02',25,5),(61,'03A02',25,5),(62,'03A02',25,5),(63,'03A02',25,5),(64,'03A02',25,5),(65,'03A02',25,5),(66,'03A02',25,5),(67,'04A02',25,5),(68,'04A02',25,5),(69,'04A02',25,5),(70,'04A02',25,5),(71,'04A02',25,5),(72,'04A02',25,5),(73,'04A02',25,5),(74,'04A02',25,5),(75,'04A02',15,4),(76,'04A02',25,5),(77,'04A02',25,5),(78,'04A02',25,5);
/*!40000 ALTER TABLE `train` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `Uid` varchar(20) NOT NULL,
  `Upassword` varchar(100) DEFAULT NULL,
  `Ubalance` decimal(6,2) DEFAULT NULL,
  `Ustate` varchar(4) DEFAULT NULL,
  PRIMARY KEY (`Uid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES ('18278409587','8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92',42.01,'out');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-12-12 14:00:48
