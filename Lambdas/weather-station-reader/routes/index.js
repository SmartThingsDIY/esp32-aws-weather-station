'use strict';

const express        = require('../node_modules/express');
const router         = express.Router();
var   moment         = require('../node_modules/moment/ts3.1-typings/moment');
var   AWS            = require('./node_modules/aws-sdk');
const documentClient = new AWS.DynamoDB.DocumentClient();

router.get('/data/get', (req, res) => {
    console.log('requesting today data');
    var today = moment().format();  // "2014-09-08T08:02:17-05:00" (ISO 8601)
    console.log('today is: ' + today);

    var params = {
        TableName: process.env.DYNAMODB_TABLE,
        ExpressionAttributeValues: {
            ":time": today
        },
        KeyConditionExpression: "#FIELD_time = :time",
        ExpressionAttributeNames: {
            "#FIELD_time": "time"
        },
        Limit: 100
    };

    documentClient.query(params, function (err, data) {
        if (err) {
            console.error(err, err.stack);
        } else {
            console.debug(data);
            res.send({
                code: '200',
                data: data
            });
        }
    });
});

module.exports = router;