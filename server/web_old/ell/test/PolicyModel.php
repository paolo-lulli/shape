<?php
    class PolicyModel {
	protected $perms;
	//////////////
	protected $perms_read    ="0";
	protected $perms_write   ="0";
	protected $perms_execute ="0";


        	function getRead() {
			#return "3333333"; //$perms_read;
			return this.$perms_read;
		}
        	function getWrite() {
			return $perms_write;
		}
        	function getExecute() {
			return $perms_execute;
		}

	}
?>
