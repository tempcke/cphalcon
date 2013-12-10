
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Model\Validator\PresenceOf
 *
 * Allows to validate if a filed have a value different of null and empty string ("")
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\PresenceOf;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      this->validate(new PresenceOf(array(
 *          "field" => 'name',
 *          "message" => 'The name is required'
 *      )));
 *      if (this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_PresenceOf) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, PresenceOf, phalcon, mvc_model_validator_presenceof, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_presenceof_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_presenceof_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;

}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_PresenceOf, validate) {

	zval *record, *fieldName, *value, *message = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", 1);
	ZEPHIR_INIT_VAR(fieldName);
	zephir_call_method_p1(fieldName, this_ptr, "getoption", _0);
	if ((Z_TYPE_P(fieldName) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, record, "readattribute", fieldName);
	if ((0 == 0)) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _0);
		if (!(zephir_is_true(message))) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "'", fieldName, "' is required");
		}
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "PresenceOf", 1);
		zephir_call_method_p3_noret(this_ptr, "appendmessage", message, fieldName, _0);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}
