<?php

class QueryBuilder{

public static function createSql($table, $fields, $types){
	$sql = "CREATE TABLE " . $table ." ( ";
        for ($i=0; $i< sizeof($fields) ; $i++){
                $sql.= "'".$fields[$i] ."'  ". $types[$i]."";
                if($i < (sizeof($fields) -1 ) ){
                        $sql.= ",";
                }
        }

	$sql.=" );";
	return $sql;
}
public static function updateSql($table, $fields, $values, $where_fields, $where_values){
 $sql = "UPDATE " . $table ." SET ";
        for ($i=0; $i< sizeof($fields) ; $i++){
                $sql.= "".$fields[$i] ." = '". $values[$i]."'";
                if($i < (sizeof($fields) -1 ) ){
                        $sql.= ",";
                }
        }
	if ( (NULL != $where_fields) && (sizeof($where_fields) > 0)  ){
                        $sql.= " WHERE ";
	}
        for ($i=0; $i< sizeof($where_fields) ; $i++){
                $sql.= "".$where_fields[$i] ." = '". $where_values[$i]."'";
                if($i < (sizeof($where_fields) -1 ) ){
                        $sql.= ",";
                }
        }
        $sql.=" ;";
        return $sql;
}
public static function insertSql($table, $fields, $values){
if (( null == $fields) || ( "" == $fields )) {
 	$sql = "INSERT INTO " . $table ." ";
	} else {
 	$sql = "INSERT INTO " . $table ." (";
	}
        for ($i=0; $i< sizeof($fields) ; $i++){
                //WAS: $sql.= "'".$fields[$i] ."' ";
   		$sql.= "".$fields[$i] ." ";                    // tolti apicetti: a mysql non vanno giu'

                if($i < (sizeof($fields) -1 ) ){
                        $sql.= ",";
                }
        }
	if (( null == $fields) || ( "" == $fields )) {
        	$sql.=" values (";
	} else {
        	$sql.=") values (";
	}
        for ($i=0; $i< sizeof($values) ; $i++){
                $sql.= "'".$values[$i] ."' ";
                if($i < (sizeof($values) -1 ) ){
                        $sql.= " , ";
                }
        }
        $sql.=");";
        return $sql;
}
//public static function deleteSql($table, $fields, $values , $where_fields, $where_values){
public static function deleteSql($table, $where_fields, $where_values){
	//$sql = "DELETE FROM TABLE " . $table;
	$sql = "DELETE FROM " . $table . " ";

	if( sizeof($where_fields) > 0) {
		$sql.=" WHERE ";
	}
        for ($i=0; $i< sizeof($where_fields) ; $i++){
                $sql.= " ".$where_fields[$i] ."  = '". $where_values[$i]."'";
                if($i < (sizeof($where_fields) -1 ) ){
                        $sql.= " AND ";
                }
        }
	return $sql;
}

public static function selectAllSql($table, $fields, $values){
	$sql = "SELECT * FROM " . $table;
	if( sizeof($fields) > 0) {
		$sql.=" WHERE ";
	}
	for ($i=0; $i< sizeof($fields) ; $i++){
		$sql.= $fields[$i] ." = ". $values[$i];	
		if($i < (sizeof($fields) -1 ) ){
			$sql.= " AND ";
		}
	}
	$sql.=" ;";
	return $sql;
}

public static function selectSql($table, $fields, $values, $selected, $aliases ){
	if ( (NULL != $selected) && (sizeof($selected) != 0 ) ){
        	for ($i=0; $i< sizeof($selected) ; $i++){
			if ( (NULL != $aliases) && (sizeof($aliases) == sizeof($selected) )){
				$sel_sql .= " ". $selected[$i] ." as ". $aliases[$i];
			} else {
				$sel_sql .= " ". $selected[$i];
			}
			if($i < (sizeof($selected) -1 ) ){
				$sel_sql.= " , ";
			}
		}

	} else {
		$sel_sql =" * ";
	} 
        $sql = "SELECT". $sel_sql.  " FROM " . $table ." WHERE ";

        for ($i=0; $i< sizeof($fields) ; $i++){
                //WAS: $sql.= $fields[$i] ." = ". $values[$i];
		$sql.= "". $fields[$i] ." = '". $values[$i] ."' ";
                if($i < (sizeof($fields) -1 ) ){
                        $sql.= " AND ";
                }
        }
        $sql.=" ;";
        return $sql;
}


}

?>
