-----------------------------
ConsumerConfig				 |
-----------------------------
	# 消息消费者配置
	# 配置项
		bootstrap.servers
			* kafka集群的节点
			* ip:port
			* 连接多个使用逗号分隔

		client.dns.lookup
		group.id
			* 设置消费组,默认值为空字符串

		session.timeout.ms
		heartbeat.interval.ms
		partition.assignment.strategy
			* 消费者与topic之间的分区分配策略

		metadata.max.age.ms
		enable.auto.commit
			* 是否开启自动提交消费位移,默认值为:true

		auto.commit.interval.ms
			* * 设置两次位移记录提交的间隔,默认: 50000(ms) 也就是5秒

		client.id
			* 当前消费者的id
			* 如果不设置,会自动的生成一个非空字符串(consumer-[编号])
				consumer-1....consumer-x

		max.partition.fetch.bytes
		send.buffer.bytes
		receive.buffer.bytes
		fetch.min.bytes
		fetch.max.bytes
		fetch.max.wait.ms
		reconnect.backoff.ms
		reconnect.backoff.max.ms
		retry.backoff.ms
		auto.offset.reset
			* 当消费者找不到消费偏移量记录的时候,从哪里开始进行消费
			* 枚举值:
				earliest	重置为最早的偏移量,从头开始消费
				latest		将偏移重置为最新偏移量,通俗的说就是不消费以前的消息了,从下条消息开始消费(默认)
				none		如果没有找到偏移量记录,抛出异常


		check.crcs
		metrics.sample.window.ms
		metrics.num.samples
		metrics.recording.level
		metric.reporters
		key.deserializer
		value.deserializer
			* 设置value和key的解码器

		request.timeout.ms
			* 默认的网络请求超时时间

		default.api.timeout.ms
		connections.max.idle.ms
		interceptor.classes
		max.poll.records
		max.poll.interval.ms
		exclude.internal.topics
		internal.leave.group.on.close
		isolation.level
		security.protocol
		ssl.protocol
		ssl.provider
		ssl.cipher.suites
		ssl.enabled.protocols
		ssl.keystore.type
		ssl.keystore.location
		ssl.keystore.password
		ssl.key.password
		ssl.truststore.type
		ssl.truststore.location
		ssl.truststore.password
		ssl.keymanager.algorithm
		ssl.trustmanager.algorithm
		ssl.endpoint.identification.algorithm
		ssl.secure.random.implementation
		sasl.kerberos.service.name
		sasl.kerberos.kinit.cmd
		sasl.kerberos.ticket.renew.window.factor
		sasl.kerberos.ticket.renew.jitter
		sasl.kerberos.min.time.before.relogin
		sasl.login.refresh.window.factor
		sasl.login.refresh.window.jitter
		sasl.login.refresh.min.period.seconds
		sasl.login.refresh.buffer.seconds
		sasl.mechanism
		sasl.jaas.config
		sasl.client.callback.handler.class
		sasl.login.callback.handler.class
		sasl.login.class

	# 构造函数
		ProducerConfig(Properties props)
		ProducerConfig(Map<String, Object> props)
	
	# 静态方法
		Map<String, Object> addSerializerToConfig(Map<String, Object> configs,Serializer<?> keySerializer, Serializer<?> valueSerializer)
		Properties addSerializerToConfig(Properties properties,Serializer<?> keySerializer,Serializer<?> valueSerializer)
		Set<String> configNames()
			* 返回可配置的key

		void main(String[] args)
			* main函数,以html格式打印配置和说明
		