<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Inline\Js;

use UnitTester;

class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getContent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineJsGetContent(UnitTester $I)
    {
        $I->wantToTest("Assets\Inline\Js - getContent()");
        $I->skipTest("Need implementation");
    }
}